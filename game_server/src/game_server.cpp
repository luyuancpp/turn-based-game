#include "game_server.h"

#include "muduo/base/Logging.h"
#include "muduo/base/CrossPlatformAdapterFunction.h"

#include "src/game_config/all_config.h"
#include "src/game_config/deploy_json.h"
#include "src/game_config/region_config.h"

#include "src/game_logic/comp/scene_comp.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/game_registry.h"
#include "src/network/gate_node.h"
#include "src/service/logic/player_service.h"
#include "src/service/logic/server_service.h"
#include "src/service/server_replied.h"
#include "src/network/deploy_rpcclient.h"
#include "src/network/node_info.h"
#include "src/pb/pbc/msgmap.h"
#include "src/system/redis_system.h"

GameServer* g_gs = nullptr;

GameServer::GameServer(muduo::net::EventLoop* loop)
    :loop_(loop),
     redis_(std::make_shared<PbSyncRedisClientPtr::element_type>()){}

void GameServer::Init()
{
    g_gs = this; 

    InitConfig();
    global_entity() = registry.create();
    registry.emplace<GsServerType>(global_entity(), GsServerType{ GameConfig::GetSingleton().config_info().server_type() });
    LOG_INFO << "server type" << GameConfig::GetSingleton().config_info().server_type();
    InitMsgService();

    InitPlayerServcie();
    
    InitNetwork();
}

void GameServer::InitConfig()
{
	GameConfig::GetSingleton().Load("game.json");
	DeployConfig::GetSingleton().Load("deploy.json");
	RegionConfig::GetSingleton().Load("region.json");
    LoadAllConfig();
}

void GameServer::InitNetwork()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_session_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_session_->subscribe<RegisterStubEvent>(deploy_stub_);
    deploy_session_->subscribe<OnConnected2ServerEvent>(*this);
    deploy_session_->connect();
}

void GameServer::ServerInfo(ServerInfoRpc replied)
{
    auto& resp = replied->s_rp_;
    auto& info = replied->s_rp_->info();
   
    auto& regioninfo = info.regin_info();
    InetAddress region_addr(regioninfo.ip(), regioninfo.port());
   
    region_session_ = std::make_unique<RpcClient>(loop_, region_addr);
    
    InetAddress serverAddr(info.redis_info().ip(), info.redis_info().port());
    g_redis_system.Init(serverAddr);

    StartGsRpc rpc(std::make_shared<StartGsRpc::element_type>());
    rpc->s_rq_.set_group(GameConfig::GetSingleton().config_info().group_id());
    rpc->s_rq_.mutable_my_info()->set_ip(muduo::ProcessInfo::localip());
    rpc->s_rq_.mutable_my_info()->set_id(gs_info_.id());
    rpc->s_rq_.mutable_rpc_client()->set_ip(deploy_session_->local_addr().toIp());
    rpc->s_rq_.mutable_rpc_client()->set_port(deploy_session_->local_addr().port());
    deploy_stub_.CallMethod(
        &GameServer::StartGsDeployReplied,
        rpc,
        this,
        &deploy::DeployService_Stub::StartGS);

	RegionRpcClosureRpc rcp(std::make_shared<RegionRpcClosureRpc::element_type>());
    rcp->s_rq_.set_region_id(RegionConfig::GetSingleton().config_info().region_id());
	deploy_stub_.CallMethod(
		&GameServer::RegionInfoReplied,
        rcp,
		this,
		&deploy::DeployService_Stub::RegionInfo);
}

void GameServer::StartGsDeployReplied(StartGsRpc replied)
{
    Connect2Region();

    auto& redisinfo = replied->s_rp_->redis_info();
	redis_->Connect(redisinfo.ip(), redisinfo.port(), 1, 1);

    gs_info_ = replied->s_rp_->my_info();
    InetAddress node_addr(gs_info_.ip(), gs_info_.port());
    server_ = std::make_shared<RpcServerPtr::element_type>(loop_, node_addr);
    server_->subscribe<OnBeConnectedEvent>(*this);
    server_->registerService(&gs_service_impl_);
    for (auto& it : g_server_nomal_service)
    {
        server_->registerService(it.get());
    }
    server_->start();   
}

void GameServer::RegionInfoReplied(RegionRpcClosureRpc replied)
{
    //connect master
    auto& resp = replied->s_rp_;
	auto& regionmaster = resp->region_masters();
	for (int32_t i = 0; i < regionmaster.masters_size(); ++i)
	{
		auto& masterinfo = regionmaster.masters(i);
		InetAddress master_addr(masterinfo.ip(), masterinfo.port());
		auto it = g_ms_nodes->emplace(masterinfo.id(), std::make_shared<MsNode>());
		auto& ms = *it.first->second;
		ms.session_ = std::make_shared<MasterSessionPtr::element_type>(loop_, master_addr);
		ms.node_info_.set_node_id(masterinfo.id());
		auto& ms_node_session = ms.session_;
        auto& ms_stub = registry.emplace<RpcStub<msservice::MasterNodeService_Stub>>(ms.ms_);
        ms_node_session->subscribe<RegisterStubEvent>(ms_stub);
		ms_node_session->subscribe<RegisterStubEvent>(g2ms_stub_);
		ms_node_session->registerService(&gs_service_impl_);
        for (auto& it : g_server_nomal_service)
        {
            ms_node_session->registerService(it.get());
        }
		ms_node_session->subscribe<OnConnected2ServerEvent>(*this);
		ms_node_session->connect();
	}
}

void GameServer::Register2Master(MasterSessionPtr& ms_node)
{
    ServerReplied::StartGsMasterRpc rpc(std::make_shared<ServerReplied::StartGsMasterRpc::element_type>());
    auto& master_local_addr = ms_node->local_addr();
    msservice::StartGsRequest& request = rpc->s_rq_;
    auto session_info = request.mutable_rpc_client();
    auto node_info = request.mutable_rpc_server();
    session_info->set_ip(master_local_addr.toIp());
    session_info->set_port(master_local_addr.port());
    node_info->set_ip(gs_info_.ip());
    node_info->set_port(gs_info_.port());
    request.set_server_type(registry.get<GsServerType>(global_entity()).server_type_);
    request.set_gs_node_id(gs_info_.id());
    g2ms_stub_.CallMethod(
        &ServerReplied::StartGsMasterReplied,
        rpc,
        &ServerReplied::GetSingleton(),
        &msservice::MasterNodeService_Stub::StartGs);
}

void GameServer::Register2Region()
{
    auto server_type = registry.get<GsServerType>(global_entity()).server_type_;
    if (!(server_type == kMainSceneCrossServer ||
        server_type == kRoomSceneCrossServer))
    {
        return;
    }
	ServerReplied::StartCrossGsRpc rpc(std::make_shared< ServerReplied::StartCrossGsRpc::element_type>());
	auto& rq = rpc->s_rq_;
	auto session_info = rq.mutable_rpc_client();
	auto node_info = rq.mutable_rpc_server();
	session_info->set_ip(region_session_->local_addr().toIp());
	session_info->set_port(region_session_->local_addr().port());
	node_info->set_ip(gs_info_.ip());
	node_info->set_port(gs_info_.port());
    rq.set_server_type(server_type);
	rq.set_gs_node_id(gs_info_.id());
	rg_stub_.CallMethod(
		&ServerReplied::StartCrossGsRegionReplied,
		rpc,
		&ServerReplied::GetSingleton(),
		&regionservcie::RgService_Stub::StartCrossGs);

}

void GameServer::receive(const OnConnected2ServerEvent& es)
{
    auto& conn = es.conn_;
    if (deploy_session_->peer_addr().toIpPort() == conn->peerAddress().toIpPort())
    {
        // started 
        if (nullptr != server_)
        {
            return;
        }

        EventLoop::getEventLoopOfCurrentThread()->queueInLoop(
            [this]() ->void
            {
                ServerInfoRpc rpc(std::make_shared<ServerInfoRpc::element_type>());
                rpc->s_rq_.set_group(GameConfig::GetSingleton().config_info().group_id());
                rpc->s_rq_.set_region_id(RegionConfig::GetSingleton().config_info().region_id());
                deploy_stub_.CallMethod(
                    &GameServer::ServerInfo,
                    rpc,
                    this,
                    &deploy::DeployService_Stub::ServerInfo);
            }
        );
    }

    for (auto& it : *g_ms_nodes)
    {
        auto& ms_node = it.second;
        auto& master_session = ms_node->session_;
        if (conn->connected() &&
            IsSameAddr(master_session->peer_addr(), conn->peerAddress()))
        {
            EventLoop::getEventLoopOfCurrentThread()->queueInLoop(std::bind(&GameServer::Register2Master, this, master_session));
            break;
        }
        // ms ??????????????????
    }

    if (nullptr != region_session_)
    {
		if (conn->connected() && 
            IsSameAddr(region_session_->peer_addr(), conn->peerAddress()))
		{
			EventLoop::getEventLoopOfCurrentThread()->queueInLoop(std::bind(&GameServer::Register2Region, this));
		}
		else if (!conn->connected() &&
			IsSameAddr(region_session_->peer_addr(), conn->peerAddress()))
		{

		}
    }
  
}

void GameServer::receive(const OnBeConnectedEvent& es)
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
			auto gatenode = registry.try_get<GateNodePtr>(e);//??????gate
			if (nullptr != gatenode && (*gatenode)->node_info_.node_type() == kGatewayNode)
			{
                g_gate_nodes->erase((*gatenode)->node_info_.node_id());
			}
			registry.destroy(e);
			break;
		}
    }
}

void GameServer::Connect2Region()
{
    region_session_->subscribe<RegisterStubEvent>(rg_stub_);
    region_session_->registerService(&gs_service_impl_);
    region_session_->subscribe<OnConnected2ServerEvent>(*this);
    region_session_->connect();
}
