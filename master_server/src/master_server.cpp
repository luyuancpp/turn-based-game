#include "master_server.h"

#include "muduo/base/Logging.h"
#include "muduo//net/EventLoop.h"

#include "src/game_config/all_config.h"
#include "src/game_config/deploy_json.h"
#include "src/game_config/region_config.h"

#include "src/network/gate_node.h"
#include "src/network/gs_node.h"
#include "src/game_logic/scene/scene_factories.h"
#include "src/game_logic/comp/player_comp.h"
#include "src/game_logic/game_registry.h"
#include "src/network/deploy_rpcclient.h"
#include "src/service/logic/player_service.h"
#include "src/service/logic/server_service.h"
#include "src/pb/pbc/msgmap.h"

#include "gs_service.pb.h"
#include "gw_service.pb.h"

using namespace common;
using namespace muduo;
using namespace net;

MasterServer* g_ms_node = nullptr;

MasterServer::MasterServer(muduo::net::EventLoop* loop)
    : loop_(loop),
      redis_(std::make_shared<RedisClient>())
{ 
    global_entity() = reg.create();
}    

void MasterServer::Init()
{
    g_ms_node = this;
    InitConfig();
    InitMsgService();
    InitGlobalEntities();
    InitPlayerServcie();

    //connect 
    Connect2Deploy();
}

void MasterServer::Connect2Deploy()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_rpc_client_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_rpc_client_->subscribe<RegisterStubEvent>(deploy_stub_);
    deploy_rpc_client_->subscribe<OnConnected2ServerEvent>(*this);
    deploy_rpc_client_->connect();
}

void MasterServer::StartServer(ServerInfoRpcRC cp)
{
    serverinfos_ = cp->s_rp_->info();
    auto& databaseinfo = serverinfos_.database_info();
    InetAddress database_addr(databaseinfo.ip(), databaseinfo.port());
    db_rpc_client_ = std::make_unique<RpcClient>(loop_, database_addr);
    db_rpc_client_->subscribe<RegisterStubEvent>(db_node_stub_);
    db_rpc_client_->connect();    

    Connect2Region();
	
    auto& myinfo = serverinfos_.master_info();
    InetAddress master_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_shared<muduo::net::RpcServer>(loop_, master_addr);
    server_->subscribe<OnBeConnectedEvent>(*this);

    server_->registerService(&node_service_impl_);
    for (auto& it : g_server_nomal_service)
    {
        server_->registerService(it.get());
    }
    server_->start();
}

void MasterServer::StartMsRegionReplied(StartMsReplied cp)
{

}

void MasterServer::DoGateConnectGs(entt::entity gs, entt::entity gate)
{
    auto& connection_info = reg.get<InetAddress>(gs);
    gwservice::StartGSRequest request;
    request.set_ip(connection_info.toIp());
    request.set_port(connection_info.port());
    request.set_gs_node_id(reg.get<GsDataPtr>(gs)->node_id());
	auto& gate_session = reg.get<GateNodePtr>(gate)->session_;
	gate_session.Send(request);
}

void MasterServer::AddGsNode(entt::entity gs)
{
    auto& gsnode = reg.get<GsNodePtr>(gs);
    g_gs_nodes.emplace(gsnode->node_info_.node_id(), gs);
}

void MasterServer::receive(const OnConnected2ServerEvent& es)
{
	auto& conn = es.conn_;
    if (conn->connected())
    {
		// started 
		if (nullptr == server_)
		{
			ServerInfoRpcRC cp(std::make_shared<ServerInfoRpcClosure>());
			cp->s_rq_.set_group(GameConfig::GetSingleton().config_info().group_id());
			cp->s_rq_.set_region_id(RegionConfig::GetSingleton().config_info().region_id());
			deploy_stub_.CallMethod(
				&MasterServer::StartServer,
				cp,
				this,
				&deploy::DeployService_Stub::ServerInfo);
		}
		
		if (nullptr != region_session_)
		{
			if (conn->connected() && IsSameAddr(region_session_->peer_addr(), conn->peerAddress()))
			{
				EventLoop::getEventLoopOfCurrentThread()->runInLoop(std::bind(&MasterServer::Register2Region, this));
			}
			else if(!conn->connected() && IsSameAddr(region_session_->peer_addr(), conn->peerAddress()))
			{

			}
		}
    }
	else
	{
		
	}
	
}

void MasterServer::receive(const OnBeConnectedEvent& es)
{
    auto& conn = es.conn_;
    if (conn->connected())
    {
		auto e = reg.create();
		reg.emplace<RpcServerConnection>(e, RpcServerConnection{ conn });
    }
    else
    {
		auto& peer_addr = conn->peerAddress();
		for (auto e : reg.view<RpcServerConnection>())
		{
			auto& local_addr = reg.get<RpcServerConnection>(e).conn_->peerAddress();
			if (local_addr.toIpPort() != peer_addr.toIpPort())
			{
				continue;
			}
            auto gsnode = reg.try_get<GsNodePtr>(e);//如果是游戏逻辑服则删除
            if (nullptr != gsnode && (*gsnode)->node_info_.node_type() == kGsNode)
            {
                g_gs_nodes.erase((*gsnode)->node_info_.node_id());
            }
			auto gatenode = reg.try_get<GateNodePtr>(e);//如果是gate
			if (nullptr != gatenode && (*gatenode)->node_info_.node_type() == kGateWayNode)
			{
                g_gate_nodes.erase((*gatenode)->node_info_.node_id());
			}
			reg.destroy(e);
			break;
		}
    }


}

void MasterServer::InitConfig()
{
    GameConfig::GetSingleton().Load("game.json");
    DeployConfig::GetSingleton().Load("deploy.json");
    RegionConfig::GetSingleton().Load("region.json");
    loadallconfig();
}

void MasterServer::InitGlobalEntities()
{
    MakeScenes();
}

void MasterServer::Connect2Region()
{
	auto& regioninfo = serverinfos_.regin_info();
	InetAddress region_addr(regioninfo.ip(), regioninfo.port());
	region_session_ = std::make_unique<RpcClient>(loop_, region_addr);
	region_session_->subscribe<RegisterStubEvent>(rg_stub_);
	region_session_->registerService(&node_service_impl_);
	region_session_->subscribe<OnConnected2ServerEvent>(*this);
	region_session_->connect();
}

void MasterServer::Register2Region()
{
    auto& myinfo = serverinfos_.master_info();
    StartMsReplied cp(std::make_shared<StartMsReplied::element_type>());
	auto& rq = cp->s_rq_;
	auto session_info = rq.mutable_rpc_client();
	auto node_info = rq.mutable_rpc_server();
	session_info->set_ip(region_session_->local_addr().toIp());
	session_info->set_port(region_session_->local_addr().port());
	node_info->set_ip(myinfo.ip());
	node_info->set_port(myinfo.port());
	rq.set_ms_node_id(myinfo.id());
	rg_stub_.CallMethod(
		&MasterServer::StartMsRegionReplied,
		cp,
		this,
		&regionservcie::RgService_Stub::StartMs);
}