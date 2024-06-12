#pragma once
#undef  TEXT//为了导航网格能编译过
#include "muduo/net/TcpServer.h"
#include "muduo/net/EventLoop.h"

#include "handler/game_service_handler.h"
#include "network/rpc_server.h"
#include "network/rpc_client.h"

#include "redis_client/redis_client.h"
#include "network/rpc_msg_route.h"

#include "common_proto/deploy_service.pb.h"

class GameNode : muduo::noncopyable
{
public:
    using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;

    GameNode(muduo::net::EventLoop* loop);
    ~GameNode();

    inline const NodeInfo& node_info()const { return node_info_; }

    void Init();

    void InitConfig();

    void StartServer(const ::servers_info_data& info);

    void RegisterGameToCentre(RpcClientPtr& centre_session);

    void Receive1(const OnConnected2ServerEvent& es);
    void Receive2(const OnBeConnectedEvent& es);

    const game_server_db& game_node_info() const { return   node_net_info_.game_info(); }
    inline NodeId game_node_id()const { return node_info().node_id();  }
    uint32_t game_node_type() const{ return node_info().game_node_type(); }
private:    
    void InitNodeByReqInfo();
    void Connect2Centre();

    muduo::net::EventLoop* loop_{ nullptr };

    PbSyncRedisClientPtr redis_;

    RpcServerPtr server_;
    servers_info_data node_net_info_;

    NodeInfo node_info_;

    GameServiceHandler game_service_;
};

extern GameNode* g_game_node;
