#include "c2gw.h"

#include  <functional>
#include <memory>

#include "muduo/base/Logging.h"
#include "muduo/net/TcpConnection.h"

#include "src/gateway_server.h"
#include "src/game_logic/game_registry.h"
#include "src/network/gs_node.h"
#include "src/network/login_node.h"
#include "src/game_logic/tips_id.h"
#include "src/network/rpc_closure.h"
#include "src/util/random.h"

#include "login_service.pb.h"

std::unordered_set<Guid> g_connected_ids;
ServerSequence32 g_server_sequence_;

extern std::unordered_set<uint32_t> g_open_player_msgids;

ClientReceiver::ClientReceiver(ProtobufCodec& codec, 
    ProtobufDispatcher& dispatcher)
    : codec_(codec),
      dispatcher_(dispatcher)
{
    dispatcher_.registerMessageCallback<LoginRequest>(
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

ClientReceiver::RpcStubgw2l& ClientReceiver::login_stub()
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
        return *it.second.login_stub_;
    }
    return *g_login_nodes.begin()->second.login_stub_;
}

void ClientReceiver::OnConnection(const muduo::net::TcpConnectionPtr& conn)
{
    //改包把消息发给其他玩家怎么办
    //todo 玩家没登录直接发其他消息，乱发消息
    if (!conn->connected())
    {
        auto session_id = tcp_session_id(conn);
        //断了线之后不能把消息串到别人的地方，串话
        //如果我没登录就发送其他协议到master game server 怎么办
        {
            //此消息一定要发，不能值通过ms 的gw disconnect去发
            //如果我的登录还没到ms,gw的disconnect 先到，登录后到，那么ms server 永远删除不了这个sessionid了
			gw2l::DisconnectRequest request;
			request.set_session_id(session_id);
			login_stub().CallMethod(request, &gw2l::LoginService_Stub::Disconnect);
        }
        // master
        {
            msservice::DisconnectRequest request;
            request.set_session_id(session_id);
            g_gateway_server->gw2ms_stub().CallMethod(request, &msservice::MasterNodeService_Stub::OnGwDisconnect);
        }
        g_client_sessions_->erase(session_id);
        if (conn.use_count() == 1)//两处，一处是rpc server 返回,返回证明已经断开，而且该连接没有消息要处理了
        { 
            g_connected_ids.erase(session_id); 
        }
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
    LoginRpc rpc(std::make_shared<LoginRpc::element_type>(conn));
    rpc->s_rq_.set_account(std::move(message->account()));
    rpc->s_rq_.set_password(std::move(message->password()));
    rpc->s_rq_.set_session_id(rpc->session_id());
    login_stub().CallMethod(&ClientReceiver::OnServerLoginReplied,
        rpc, 
        this, 
        &gw2l::LoginService_Stub::Login);
}

void ClientReceiver::OnServerLoginReplied(LoginRpc replied)
{
    auto& player_list = replied->s_rp_->account_player().simple_players().players();
    for (auto it : player_list)
    {
        auto p = replied->c_rp_.add_players();
        p->set_player_id(it.player_id());
    }
    codec_.send(replied->client_conn_, replied->c_rp_);
}

void ClientReceiver::OnCreatePlayer(const muduo::net::TcpConnectionPtr& conn, 
                                    const CreatePlayerRequestPtr& message, 
                                    muduo::Timestamp)
{
    auto rpc(std::make_shared<CreatePlayeRpc::element_type>(conn));
    rpc->s_rq_.set_session_id(rpc->session_id());
    login_stub().CallMethod(&ClientReceiver::OnServerCreatePlayerReplied,
        rpc, 
        this, 
        &gw2l::LoginService_Stub::CreatPlayer);
}

void ClientReceiver::OnServerCreatePlayerReplied(CreatePlayeRpc replied)
{
    auto& player_list = replied->s_rp_->account_player().simple_players().players();
    for (auto it : player_list)
    {
        auto p = replied->c_rp_.add_players();
        p->set_player_id(it.player_id());
    }
    codec_.send(replied->client_conn_, replied->c_rp_);
}

void ClientReceiver::OnEnterGame(const muduo::net::TcpConnectionPtr& conn, 
                                const EnterGameRequestPtr& message, 
                                muduo::Timestamp)
{
    auto rpc(std::make_shared<EnterGameRpc::element_type>(conn));
    rpc->s_rq_.set_session_id(rpc->session_id());
    rpc->s_rq_.set_player_id(message->player_id());
    login_stub().CallMethod(&ClientReceiver::OnServerEnterGameReplied,
        rpc,
        this,
        &gw2l::LoginService_Stub::EnterGame);
}

void ClientReceiver::OnServerEnterGameReplied(EnterGameRpc replied)
{
    //这里设置player id 还是会有串话问题，断线以后重新上来一个新的玩家，同一个connection，到时候可以再加个token判断   
	replied->c_rp_.mutable_error()->CopyFrom(replied->s_rp_->error());
	codec_.send(replied->client_conn_, replied->c_rp_);
	return;
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
		auto rpc(std::make_shared<GsPlayerServiceRpc::element_type>(conn));
        rpc->s_rq_.set_request(request->request());
        rpc->s_rq_.set_session_id(session_id);
        rpc->s_rq_.set_msg_id(request->msg_id());
        rpc->c_rp_.set_id(request->id());
        rpc->c_rp_.set_msg_id(request->msg_id());
        gs->second.gs_stub_->CallMethod(&ClientReceiver::OnGsPlayerServiceReplied,
			rpc,
			this,
			&gsservice::GsService_Stub::GwPlayerService);
    }
}

void ClientReceiver::OnGsPlayerServiceReplied(GsPlayerServiceRpc replied)
{
    auto& crp = replied->c_rp_;
    crp.set_body(std::move(replied->s_rp_->response()));
    codec_.send(replied->client_conn_, crp);
}


