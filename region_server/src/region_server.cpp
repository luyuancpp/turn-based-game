#include "region_server.h"

#include "muduo/base/Logging.h"

#include "src/game_config/deploy_json.h"
#include "src/game_config/mainscene_config.h"
#include "src/game_config/region_config.h"
#include "src/game_logic/game_registry.h"
#include "src/network/server_component.h"
#include "src/network/gs_node.h"
#include "src/network/ms_node.h"


RegionServer* g_region_server = nullptr;

void set_server_squence_node_id(uint32_t node_id);


RegionServer::RegionServer(muduo::net::EventLoop* loop): loop_(loop){}

void RegionServer::Init()
{
    g_region_server = this;

    RegionConfig::GetSingleton().Load("region.json");
    DeployConfig::GetSingleton().Load("deploy.json");

    mainscene_config::GetSingleton().load();

    ConnectDeploy();
}

void RegionServer::ConnectDeploy()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_rpc_client_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_rpc_client_->subscribe<RegisterStubEvent>(deploy_stub_);
    deploy_rpc_client_->subscribe<OnConnected2ServerEvent>(*this);
    deploy_rpc_client_->connect();
}

void RegionServer::StartServer(RegionInfoRpc replied)
{
    auto& myinfo = replied->s_rp_->info();
    InetAddress region_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_shared<RpcServerPtr::element_type>(loop_, region_addr);
    server_->registerService(&impl_);
    server_->subscribe<OnBeConnectedEvent>(*this);
    server_->start();
}

void RegionServer::SceneSqueueNodeId(SceneNodeSequeIdRpc replied)
{
    set_server_squence_node_id(replied->s_rp_->node_id());
}

void RegionServer::receive(const OnConnected2ServerEvent& es)
{
    // started 
    if (nullptr != server_)
    {
        return;
    }
	if (es.conn_->connected())
	{
        {
            RegionInfoRpc rpc(std::make_shared<RegionInfoRpc::element_type>());
            rpc->s_rq_.set_region_id(RegionConfig::GetSingleton().config_info().region_id());
            deploy_stub_.CallMethod(
                &RegionServer::StartServer,
                rpc,
                this,
                &deploy::DeployService_Stub::StartRegionServer);
        }
			

        {
            SceneNodeSequeIdRpc rpc(std::make_shared<SceneNodeSequeIdRpc::element_type>());
            deploy_stub_.CallMethod(
                &RegionServer::SceneSqueueNodeId,
                rpc,
                this,
                &deploy::DeployService_Stub::SceneSqueueNodeId);
        }
	}
      
}

void RegionServer::receive(const OnBeConnectedEvent& es)
{
	auto& conn = es.conn_;
    if (conn->connected())
    {
        auto e = registry.create();
        registry.emplace<RpcServerConnection>(e, RpcServerConnection{ conn });
    }
    else
    {
		auto& peer_addr = conn->peerAddress();
		for (auto e : registry.view<RpcServerConnection>())
		{
			auto& local_addr = registry.get<RpcServerConnection>(e).conn_->peerAddress();
			if (local_addr.toIpPort() != peer_addr.toIpPort())
			{
				continue;
			}
			auto gsnode = registry.try_get<GsNodePtr>(e);//??????????????????????
			if (nullptr != gsnode && (*gsnode)->node_info_.node_type() == kGsNode)
			{
				g_gs_nodes->erase((*gsnode)->node_info_.node_id());
			}
            // ms ??????????????????????
			registry.destroy(e);
			break;
		}
    }		
}
