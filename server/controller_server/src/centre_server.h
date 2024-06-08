#pragma once

#include "entt/src/entt/entity/registry.hpp"

#include "src/handler/centre_service_handler.h"
#include "src/redis_client/redis_client.h"
#include "src/network/rpc_client.h"
#include "src/network/rpc_connection_event.h"
#include "src/network/rpc_server.h"
#include "src/network/server_component.h"

#include "common_proto/deploy_service.pb.h"
#include "common_proto/database_service.pb.h"
#include "logic_proto/lobby_scene.pb.h"

class CentreServer : muduo::noncopyable
{
public:
	
	using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;
	
	CentreServer(muduo::net::EventLoop* loop);
	~CentreServer();

	inline PbSyncRedisClientPtr& redis_client() { return redis_; }
	inline uint32_t controller_node_id()const { return serverinfos_.controller_info().id(); }
	inline RpcClientPtr& lobby_node() { return lobby_session_; }
	inline RpcClientPtr& database_node() { return db_session_; }
	inline const NodeInfo& node_info()const { return node_info_; }

	void Init();
	void LetGateConnect2Gs(entt::entity gs, entt::entity gate);

    void StartServer(const ::servers_info_data& info);

	void Receive1(const OnConnected2ServerEvent& es);
	void Receive2(const OnBeConnectedEvent& es);

private:

	void InitConfig();
	void InitMq();

	void Connect2Deploy();
	void Register2Lobby();

	void InitNodeServer();

	muduo::net::EventLoop* loop_{ nullptr };
	PbSyncRedisClientPtr redis_;
	RpcServerPtr server_;

	RpcClientPtr deploy_session_;
	RpcClientPtr lobby_session_;
	RpcClientPtr db_session_;

	CentreServiceHandler contoller_service_;

	NodeInfo node_info_;
	servers_info_data serverinfos_;
};

extern CentreServer* g_controller_node;


