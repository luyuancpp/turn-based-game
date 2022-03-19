#include "master_server.h"

#include "muduo/base/Logging.h"

#include "src/game_config/all_config.h"
#include "src/game_config/deploy_json.h"
#include "src/game_config/region_config.h"

#include "src/network/gate_node.h"
#include "src/network/gs_node.h"
#include "src/factories/scene_factories.hpp"
#include "src/factories/server_global_entity.hpp"
#include "src/game_logic/comp/player_comp.hpp"
#include "src/server_common/deploy_rpcclient.h"
#include "src/game_logic/game_registry.h"

#include "ms2gs.pb.h"
#include "ms2gw.pb.h"

using namespace common;

master::MasterServer* g_ms_node = nullptr;

namespace master
{
MasterServer::MasterServer(muduo::net::EventLoop* loop)
    : loop_(loop),
      redis_(std::make_shared<RedisClient>()),
      g2ms_impl_(),
      gw2ms_impl_()
{ 
    global_entity() = reg.create();
    reg.emplace<GsNodes>(global_entity());
    reg.emplace<GateNodes>(global_entity());   
}    

void MasterServer::Init()
{
    InitConfig();
    InitGlobalEntities();
}

void MasterServer::ConnectDeploy()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_rpc_client_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_rpc_client_->subscribe<RegisterStubEvent>(deploy_stub_);
    deploy_rpc_client_->subscribe<RpcClientConnectionEvent>(*this);
    deploy_rpc_client_->connect();
}

void MasterServer::StartServer(ServerInfoRpcRC cp)
{
    serverinfos_ = cp->s_rp_->info();
    auto& databaseinfo = serverinfos_.database_info();
    InetAddress database_addr(databaseinfo.ip(), databaseinfo.port());
    db_rpc_client_ = std::make_unique<RpcClient>(loop_, database_addr);
    db_rpc_client_->subscribe<RegisterStubEvent>(msl2_login_stub_);
    db_rpc_client_->connect();    

    auto& myinfo = serverinfos_.master_info();
    InetAddress master_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_shared<muduo::net::RpcServer>(loop_, master_addr);
    server_->subscribe<ServerConnectionEvent>(*this);

    server_->registerService(&l2ms_impl_);
    server_->registerService(&g2ms_impl_);
    server_->registerService(&gw2ms_impl_);
    server_->start();
}

void MasterServer::DoGateConnectGs(entt::entity gs, entt::entity gate)
{
    auto& connection_info = reg.get<InetAddress>(gs);
    ms2gw::StartGSRequest request;
    request.set_ip(connection_info.toIp());
    request.set_port(connection_info.port());
    request.set_gs_node_id(reg.get<GSDataPtrComp>(gs)->node_id());
    reg.get<GateNodePtr>(gate)->session_.Send(request, "ms2gw.Ms2gwService", "StartGS");
}

void MasterServer::OnGsNodeStart(entt::entity gs)
{
    auto& gsnode = reg.get<GsNodePtr>(gs);
    auto& gs_nodes = reg.get<GsNodes>(global_entity());
    gs_nodes.emplace(gsnode->node_info_.node_id_, gs);
}

void MasterServer::receive(const RpcClientConnectionEvent& es)
{
    if (!es.conn_->connected())
    {
        return;
    }
    // started 
    if (nullptr != server_)
    {
        return;
    }
    ServerInfoRpcRC cp(std::make_shared<ServerInfoRpcClosure>());
    cp->s_rq_.set_group(GameConfig::GetSingleton().config_info().group_id());
    cp->s_rq_.set_region_id(RegionConfig::GetSingleton().config_info().region_id());
    deploy_stub_.CallMethod(
        &MasterServer::StartServer,
        cp,
        this,
        &deploy::DeployService_Stub::ServerInfo);
}

void MasterServer::receive(const ServerConnectionEvent& es)
{
    auto& conn = es.conn_;
    if (conn->connected())
    {
		auto e = reg.create();
		reg.emplace<RpcServerConnection>(e, RpcServerConnection{ conn });
    }
    else
    {
        auto& gs_nodes = reg.get<GsNodes>(global_entity());
        auto& gate_nodes = reg.get<GateNodes>(global_entity());
		auto& peer_addr = conn->peerAddress();
		for (auto e : reg.view<RpcServerConnection>())
		{
			auto& local_addr = reg.get<RpcServerConnection>(e).conn_->peerAddress();
			if (local_addr.toIpPort() != peer_addr.toIpPort())
			{
				continue;
			}
            auto gsnode = reg.try_get<GsNodePtr>(e);//如果是游戏逻辑服则删除
            if (nullptr != gsnode && (*gsnode)->node_info_.node_type_ == GAME_SERVER_NODTE_TYPE)
            {
                gs_nodes.erase((*gsnode)->node_info_.node_id_);
            }
			auto gatenode = reg.try_get<GateNodePtr>(e);//如果是gate
			if (nullptr != gatenode && (*gatenode)->node_info_.node_type_ == GATEWAY_NOTE_TYPE)
			{
                 gate_nodes.erase((*gatenode)->node_info_.node_id_);
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
    reg.emplace<ConnectionPlayerEnitiesMap>(global_entity());
}

}//namespace master