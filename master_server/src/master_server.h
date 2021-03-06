#pragma once

#include "entt/src/entt/entity/registry.hpp"

#include "src/event/event.h"
#include "src/service/ms_service.h"
#include "src/redis_client/redis_client.h"
#include "src/network/deploy_rpcclient.h"
#include "src/network/rpc_closure.h"
#include "src/network/rpc_connection_event.h"
#include "src/network/rpc_server.h"
#include "src/network/server_component.h"

#include "deploy_service.pb.h"
#include "db_service.pb.h"
#include "logic_proto/scene_rg.pb.h"

class MasterServer : muduo::noncopyable, public Receiver<MasterServer>
{
public:
	using PbSyncRedisClientPtr = PbSyncRedisClientPtr;
	using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;
	using DbNodeStub = RpcStub<dbservice::DbService_Stub>;
	using RgNodeStub = RpcStub<regionservcie::RgService_Stub>;

	MasterServer(muduo::net::EventLoop* loop);

	inline PbSyncRedisClientPtr& redis_client() { return redis_; }
	inline uint32_t master_node_id()const { return serverinfos_.master_info().id(); }
	inline RgNodeStub& rg_stub() { return rg_stub_; }

	void Init();
	void LetGateConnect2Gs(entt::entity gs, entt::entity gate);

	void receive(const OnConnected2ServerEvent& es);
	void receive(const OnBeConnectedEvent& es);

private:

	void InitConfig();

	using ServerInfoRpc = std::shared_ptr<NormalClosure<deploy::ServerInfoRequest, deploy::ServerInfoResponse>>;
	void StartServer(ServerInfoRpc replied);

    using SceneNodeSequeIdRpc = std::shared_ptr<NormalClosure<deploy::SceneSqueueRequest, deploy::SceneSqueueResponese>>;
    void SceneSqueueNodeId(SceneNodeSequeIdRpc replied);

	void Connect2Deploy();
	void Connect2Region();
	void Register2Region();

	muduo::net::EventLoop* loop_{ nullptr };
	PbSyncRedisClientPtr redis_;
	RpcServerPtr server_;

	RpcClientPtr deploy_session_;
	DeployStub deploy_stub_;

	RpcClientPtr region_session_;
	RgNodeStub rg_stub_;

	RpcClientPtr db_session_;
	DbNodeStub db_node_stub_;

	MasterNodeServiceImpl ms_service_;

	servers_info_data serverinfos_;
};

extern MasterServer* g_ms_node;


