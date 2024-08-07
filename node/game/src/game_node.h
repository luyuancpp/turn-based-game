#pragma once
#undef  TEXT//为了导航网格能编译过

#include "muduo/net/EventLoop.h"
#include "muduo/base/AsyncLogging.h"

#include "handler/service/game_service_handler.h"
#include "network/rpc_client.h"
#include "network/rpc_connection_event.h"
#include "network/rpc_server.h"
#include "redis_client/redis_client.h"
#include "time/comp/timer_task_comp.h"
#include "type_define/type_define.h"

#include "proto/common/deploy_service.pb.h"

class GameNode : muduo::noncopyable
{
public:
    using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;

    explicit
        GameNode(muduo::net::EventLoop* loop);
    ~GameNode();

    inline const NodeInfo& GetNodeInfo()const { return nodeInfo; }
    const game_node_db& GetNodeConf() const;
    inline NodeId GetNodeId()const { return GetNodeInfo().node_id();  }
    uint32_t GetNodeType() const{ return GetNodeInfo().game_node_type(); }

    inline [[nodiscard]] muduo::AsyncLogging& Log ( ) { return muduoLog; }
    
    void SetNodeId(NodeId node_id);
    void StartServer(const ::nodes_info_data& info);
    
    void Init();
    void Exit();

    void Receive1(const OnConnected2ServerEvent& es);
    void Receive2(const OnBeConnectedEvent& es);

private:    
    void InitNodeByReqInfo();
    void Connect2Centre();

    void InitLog();
    static void InitNodeConfig();
    static void InitGameConfig();
    static void InitTimeZone();
    
    inline NodeId GetNodeConfIndex()const { return GetNodeId() - 1; }

    muduo::net::EventLoop* loop_{ nullptr };
    muduo::AsyncLogging muduoLog;

private:
    PbSyncRedisClientPtr redis;
    RpcServerPtr rpcServer;
    nodes_info_data nodeServiceInfo;
    NodeInfo nodeInfo;
    RpcClientPtr myZoneCentreNode;
    GameServiceHandler gameService;
    TimerTaskComp deployRpcTimer;
    TimerTaskComp worldTimer;
};

extern GameNode* gGameNode;
