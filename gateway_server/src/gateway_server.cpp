#include "gateway_server.h"

#include "src/game_config/deploy_json.h"
#include "src/network/gs_node.h"
#include "src/network/deploy_rpcclient.h"
#include "src/pb/pbc/msgmap.h"

#include "gs_node.pb.h"

using namespace common;

gateway::GatewayServer* g_gateway_server = nullptr; 

namespace gateway
{
void GatewayServer::LoadConfig()
{
    GameConfig::GetSingleton().Load("game.json");
    DeployConfig::GetSingleton().Load("deploy.json");
}

void GatewayServer::Init()
{
    LoadConfig();
    InitMsgService();
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_session_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_session_->subscribe<RegisterStubEvent>(deploy_stub_);
    deploy_session_->subscribe<OnConnected2ServerEvent>(*this);
    deploy_session_->connect();
}

void GatewayServer::StartServer(ServerInfoRpcRC cp)
{
    serverinfo_data_ = cp->s_rp_->info();
    g_server_sequence_.set_server_id(gate_node_id());
    auto& login_info = serverinfo_data_.login_info();
    InetAddress login_addr(login_info.ip(), login_info.port());
    login_session_ = std::make_unique<RpcClient>(loop_, login_addr);
    login_session_->connect();
    login_session_->subscribe<RegisterStubEvent>(gw2l_login_stub_);

    auto& master_info = serverinfo_data_.master_info();
    InetAddress master_addr(master_info.ip(), master_info.port());
    master_session_ = std::make_unique<RpcClient>(loop_, master_addr);
    master_session_->registerService(&node_service_impl_);
    master_session_->subscribe<RegisterStubEvent>(gw2ms_stub_);
    master_session_->subscribe<OnConnected2ServerEvent>(*this);
    master_session_->connect();        

    auto& myinfo = serverinfo_data_.gateway_info();
    InetAddress gateway_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_unique<TcpServer>(loop_, gateway_addr, "gateway");
    server_->setConnectionCallback(
        std::bind(&GatewayServer::OnConnection, this, _1));
    server_->setMessageCallback(
        std::bind(&ProtobufCodec::onMessage, &codec_, _1, _2, _3));
    server_->start();
}

void GatewayServer::receive(const OnConnected2ServerEvent& es)
{
    auto& conn = es.conn_;
    if (!conn->connected())
    {
        return;
    }

    if (IsSameAddr(conn->peerAddress(), DeployConfig::GetSingleton().deploy_info()))
    {
        // started 
        if (nullptr != server_)
        {
            return;
        }
        EventLoop::getEventLoopOfCurrentThread()->runInLoop(
            [this]() ->void
            {
                ServerInfoRpcRC c(std::make_shared<ServerInfoRpcClosure>());
                c->s_rq_.set_group(GameConfig::GetSingleton().config_info().group_id());
                deploy_stub_.CallMethod(
                    &GatewayServer::StartServer,
                    c,
                    this,
                    &deploy::DeployService_Stub::ServerInfo);
            }
        );
    }
    else if (IsSameAddr(conn->peerAddress(), serverinfo_data_.master_info()))
    {
		EventLoop::getEventLoopOfCurrentThread()->runInLoop(
            [this]() ->void
			{
				auto& master_addr = master_session_->local_addr();
				msservice::ConnectRequest request;
				request.mutable_rpc_client()->set_ip(master_addr.toIp());
				request.mutable_rpc_client()->set_port(master_addr.port());
				request.set_gate_node_id(gate_node_id());
				gw2ms_stub_.CallMethod(request, &msservice::MasterNodeService_Stub::OnGwConnect);
			}
        );
    }
    else
    {
        for (auto& it : g_gs_nodes)
        {
            if (!IsSameAddr(it.second.gs_session_->peer_addr(), conn->peerAddress()))
            {
                break;
            }
            if (conn->connected())
            {
				auto& gs_session = it.second;
				EventLoop::getEventLoopOfCurrentThread()->runInLoop(
					[this, &gs_session, &conn]() ->void
					{
						gsservice::ConnectRequest request;
						request.mutable_rpc_client()->set_ip(conn->localAddress().toIp());
						request.mutable_rpc_client()->set_port(conn->localAddress().port());
						request.set_gate_node_id(gate_node_id());
						gs_session.gs_stub_->CallMethod(request, &gsservice::GsService_Stub::GwConnectGs);
					}
				);
            }
            else
            { }
        }
    }
}

}//namespace gateway
