#include "gate_server.h"

#include "src/game_config/deploy_json.h"
#include "src/network/gs_node.h"
#include "src/network/login_node.h"
#include "src/network/server_component.h"
#include "src/pb/pbc/msgmap.h"
#include "src/pb/pbc/service_method/controller_servicemethod.h"
#include "src/pb/pbc/service_method/deploy_servicemethod.h"
#include "src/pb/pbc/service_method/game_servicemethod.h"
#include "src/service/common_proto_replied/replied_dispathcer.h"

#include "game_service.pb.h"

GateServer* g_gate_server = nullptr; 



void GateServer::LoadConfig()
{
    GameConfig::GetSingleton().Load("game.json");
    DeployConfig::GetSingleton().Load("deploy.json");
}

void GateServer::Init()
{
    g_gate_server = this;
    LoadConfig();
    InitMsgService();
    InitRepliedCallback();
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_session_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_session_->subscribe<OnConnected2ServerEvent>(*this);
    deploy_session_->connect();
}


void GateServer::StartServer()
{

    auto& myinfo = serverinfo_data_.gate_info();
    InetAddress gate_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_unique<TcpServer>(loop_, gate_addr, "gate");
    server_->setConnectionCallback(
        std::bind(&GateServer::OnConnection, this, _1));
    server_->setMessageCallback(
        std::bind(&ProtobufCodec::onMessage, &codec_, _1, _2, _3));
    server_->start();
}


void GateServer::receive(const OnConnected2ServerEvent& es)
{
    auto& conn = es.conn_;
   
    if (IsSameAddr(conn->peerAddress(), DeployConfig::GetSingleton().deploy_info()))
    {
        // started 
        if (nullptr != server_)//断线重连
        {
            return;
        }
		if (!conn->connected())
		{
			return;
		}
        EventLoop::getEventLoopOfCurrentThread()->queueInLoop(
            [this]() ->void
            {
                ServerInfoRequest rq;
                rq.set_group(GameConfig::GetSingleton().config_info().group_id());
                deploy_session()->CallMethod(DeployServiceServerInfoMethodDesc, &rq);
            }
        );
    }
    else if (IsSameAddr(conn->peerAddress(), serverinfo_data_.controller_info()))
    {
		if (!conn->connected())
		{
			return;
		}
		EventLoop::getEventLoopOfCurrentThread()->queueInLoop(
            [this]() ->void
			{
				auto& controller_node_addr = controller_node_->local_addr();
				ControllerNodeConnectRequest rq;
				rq.mutable_rpc_client()->set_ip(controller_node_addr.toIp());
				rq.mutable_rpc_client()->set_port(controller_node_addr.port());
				rq.set_gate_node_id(gate_node_id());
				controller_node_session()->CallMethod(ControllerServiceOnGateConnectMethodDesc, &rq);
			}
        );
    }
    else
    {
        //todo 断线重连
        for (auto& it : g_gs_nodes)
        {
            if (!IsSameAddr(it.second.gs_session_->peer_addr(), conn->peerAddress()))
            {
                continue;
            }
            if (conn->connected())
            {
				auto& gs_node = it.second;
				EventLoop::getEventLoopOfCurrentThread()->queueInLoop(
					[this, &gs_node, &conn]() ->void
					{
						GameNodeConnectRequest rq;
						rq.mutable_rpc_client()->set_ip(conn->localAddress().toIp());
						rq.mutable_rpc_client()->set_port(conn->localAddress().port());
						rq.set_gate_node_id(gate_node_id());
						gs_node.gs_session_->CallMethod(GameServiceGateConnectGsMethodDesc, &rq);
					}
				);
            }
            else
            { 
                //g_gs_nodes.erase()
            }
        }

        for (auto& it : g_login_nodes)
        {
            LOG_INFO << it.second.login_session_->peer_addr().toIpPort() << "," << conn->peerAddress().toIpPort();
			if (!IsSameAddr(it.second.login_session_->peer_addr(), conn->peerAddress()))
			{
				continue;
			}
            if (conn->connected())
            {
                
            }
            else
            {
                g_login_nodes.erase(it.first);
                break;
            }
        }
    }
}

void GateServer::Connect2Controller()
{
    auto& controller_node_info = serverinfo_data_.controller_info();
    InetAddress controller_addr(controller_node_info.ip(), controller_node_info.port());
    controller_node_ = std::make_unique<RpcClient>(loop_, controller_addr);
    controller_node_->registerService(&gate_service_);
    controller_node_->subscribe<OnConnected2ServerEvent>(*this);
    controller_node_->connect();
}