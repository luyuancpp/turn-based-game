#include "c2gate.h"

#include  <functional>
#include <memory>

#include "muduo/base/Logging.h"
#include "muduo/net/TcpConnection.h"

#include "src/gate_server.h"
#include "src/game_logic/game_registry.h"
#include "src/network/gs_node.h"
#include "src/network/login_node.h"
#include "src/game_logic/tips_id.h"
#include "src/network/rpc_closure.h"
#include "src/util/random.h"
#include "src/pb/pbc/service_method/controller_servicemethod.h"
#include "src/pb/pbc/service_method/game_servicemethod.h"
#include "src/pb/pbc/service_method/login_servicemethod.h"

#include "login_service.pb.h"

ServerSequence32 g_server_sequence_;

extern std::unordered_set<uint32_t> g_open_player_msgids;

ClientReceiver::ClientReceiver(ProtobufCodec& codec, 
    ProtobufDispatcher& dispatcher)
    : codec_(codec),
      dispatcher_(dispatcher)
{
    dispatcher_.registerMessageCallback<DbNodeLoginRequest>(
        std::bind(&ClientReceiver::OnLogin, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<CreatePlayerRequest>(
        std::bind(&ClientReceiver::OnCreatePlayer, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<EnterGameRequest>(
        std::bind(&ClientReceiver::OnEnterGame, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<LeaveGameRequest>(
        std::bind(&ClientReceiver::OnLeaveGame, this, _1, _2, _3));
	dispatcher_.registerMessageCallback<ClientRequest>(
		std::bind(&ClientReceiver::OnRpcClientMessage, this, _1, _2, _3));
}

RpcClientPtr& ClientReceiver::get_login_node()
{
    auto index = Random::GetSingleton().Rand<std::size_t>(0, g_login_nodes.size());
    std::size_t i = 0;
    for (auto& it : g_login_nodes)
    {
        if (i < index)
        {
            ++i;
            continue;
        }
        return it.second.login_session_;
    }
    return g_login_nodes.begin()->second.login_session_;
}

RpcClientPtr& ClientReceiver::get_login_node(uint64_t session_id)
{
    static RpcClientPtr empty_session;
    auto session_it = g_client_sessions_->find(session_id);
    if (g_client_sessions_->end() == session_it)
    {
        return empty_session;
    }
    if (!session_it->second.ValidLogin())
    {
        session_it->second.login_node_id_ = find_valid_login_node_id(session_id);
    }
    auto login_node_it = g_login_nodes.find(session_it->second.login_node_id_);
    if (g_login_nodes.end() == login_node_it)
    {
        LOG_ERROR << "player login server not found : " << session_it->second.login_node_id_;
        return empty_session;
    }
    return login_node_it->second.login_session_;
}

uint32_t ClientReceiver::find_valid_login_node_id(uint64_t session_id)
{
	auto index = session_id % g_login_nodes.size();
	std::size_t i = 0;
	for (auto& it : g_login_nodes)
	{
		if (i < index)
		{
			++i;
			continue;
		}
		return it.first;
	}
    return GateClient::kInvalidNodeId;
}

void ClientReceiver::OnConnection(const muduo::net::TcpConnectionPtr& conn)
{
    //改包把消息发给其他玩家怎么办
    //todo 玩家没登录直接发其他消息，乱发消息
    if (!conn->connected())
    {
        auto session_id = tcp_session_id(conn);
        //如果我没登录就发送其他协议到controller game server 怎么办
        {
            //此消息一定要发，不能值通过ms 的gw disconnect去发
            //如果我的登录还没到controller,gw的disconnect 先到，登录后到，那么ms server 永远删除不了这个sessionid了
			loginservice::DisconnectRequest rq;
			rq.set_session_id(session_id);
			get_login_node(session_id)->CallMethod(loginserviceDisconnectMethoddesc, &rq);
        }
        // controller
        {
            controllerservice::DisconnectRequest rq;
            rq.set_session_id(session_id);
            g_gate_server->controller_node_session()->CallMethod(controllerserviceOnGateDisconnectMethoddesc, &rq);
        }
        g_client_sessions_->erase(session_id);
    }
    else
    {
        auto id = g_server_sequence_.Generate();
        while (g_client_sessions_->find(id) != g_client_sessions_->end())
        {
            id = g_server_sequence_.Generate();
        }
        conn->setContext(id);
        GateClient gc;
        gc.conn_ = conn;
        g_client_sessions_->emplace(id, std::move(gc));
    }
}

void ClientReceiver::OnLogin(const muduo::net::TcpConnectionPtr& conn,
    const LoginRequestPtr& message,
    muduo::Timestamp)
{
    //todo login 崩溃了
    LoginNodeLoginNodeLoginRequest rq;
    rq.set_account(message->account());
    rq.set_password(message->password());
    rq.set_session_id(tcp_session_id(conn));
    get_login_node(tcp_session_id(conn))->CallMethod(loginserviceLoginMethoddesc, &rq);
}

void ClientReceiver::OnCreatePlayer(const muduo::net::TcpConnectionPtr& conn, 
                                    const CreatePlayerRequestPtr& message, 
                                    muduo::Timestamp)
{
    loginservice::CreatePlayerRequest rq;
    rq.set_session_id(tcp_session_id(conn));
    get_login_node(tcp_session_id(conn))->CallMethod(loginserviceCreatPlayerMethoddesc, &rq);
}

void ClientReceiver::OnEnterGame(const muduo::net::TcpConnectionPtr& conn, 
                                const EnterGameRequestPtr& message, 
                                muduo::Timestamp)
{
    LoginNodeEnterGameRequest rq;
    rq.set_session_id(tcp_session_id(conn));
    rq.set_player_id(message->player_id());
    get_login_node(tcp_session_id(conn))->CallMethod(loginserviceEnterGameMethoddesc, &rq);
}

void ClientReceiver::OnLeaveGame(const muduo::net::TcpConnectionPtr& conn, 
    const LeaveGameRequestPtr& message, 
    muduo::Timestamp)
{
    LeaveGameResponse response;
    codec_.send(conn, response);
}

void ClientReceiver::OnRpcClientMessage(const muduo::net::TcpConnectionPtr& conn,
    const RpcClientMessagePtr& request,
    muduo::Timestamp)
{
    auto session_id = tcp_session_id(conn);
	auto it = g_client_sessions_->find(session_id);
	if (it == g_client_sessions_->end())
	{
		return;
	}
    //检测玩家可以不可以发这个消息id过来给服务器
    auto gs = g_gs_nodes.find(it->second.gs_node_id_);
    if (g_gs_nodes.end() == gs)
    {
        //todo client error;
        return;
    }
    //todo msg id error
    if (g_open_player_msgids.find(request->msg_id()) != g_open_player_msgids.end())
    {
        gsservice::RpcClientRequest rq;
        rq.set_request(request->request());
        rq.set_session_id(session_id);
        rq.set_msg_id(request->msg_id());
        rq.set_id(request->id());
        gs->second.gs_session_->CallMethod(gsserviceClientSend2PlayerMethoddesc, &rq);
    }
}



