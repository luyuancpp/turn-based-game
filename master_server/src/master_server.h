#ifndef MASTER_SERVER_MASTER_SERVER_H_
#define MASTER_SERVER_MASTER_SERVER_H_

#include "entt/src/entt/entity/registry.hpp"

#include "src/event/event.h"
#include "src/service/l2ms.h"
#include "src/redis_client/redis_client.h"
#include "src/game/service_g2ms.h"
#include "src/service/gw2ms.h"
#include "src/server_common/deploy_rpcclient.h"
#include "src/server_common/rpc_closure.h"
#include "src/server_common/rpc_connection_event.h"
#include "src/server_common/rpc_server.h"
#include "src/server_common/server_component.h"

#include "deploy.pb.h"
#include "l2ms.pb.h"
#include "ms2db.pb.h"

namespace master
{
    class MasterServer : muduo::noncopyable, public common::Receiver<MasterServer>
    {
    public:
        using RedisClientPtr = common::RedisClientPtr;
        using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;
        using LoginStubms2db = common::RpcStub<ms2db::LoginService_Stub>;

        MasterServer(muduo::net::EventLoop* loop);           

        inline RedisClientPtr& redis_client() { return redis_; }
        inline common::RpcServerConnectionPtr& gate_client() { return gate_client_; }
        inline uint32_t master_node_id()const { return serverinfos_.master_info().id(); };

        void Init();

        void ConnectDeploy();

        using ServerInfoRpcClosure = common::RpcClosure<deploy::ServerInfoRequest,
            deploy::ServerInfoResponse>;
        using ServerInfoRpcRC = std::shared_ptr<ServerInfoRpcClosure>;
        void StartServer(ServerInfoRpcRC cp);

        void GatewayConnectGame(entt::entity ge);

        void receive(const common::RpcClientConnectionEvent& es);
        void receive(const common::ServerConnectionEvent& es);

    private:
        void OnRpcClientConnectionConnect(const muduo::net::TcpConnectionPtr& conn);
        void OnRpcClientConnectionDisConnect(const muduo::net::TcpConnectionPtr& conn);        

        void InitConfig();
        void InitGlobalEntities();

        muduo::net::EventLoop* loop_{ nullptr };
        RedisClientPtr redis_;
        RpcServerPtr server_;

        common::RpcClientPtr deploy_rpc_client_;
        deploy::DeployStub deploy_stub_;

        common::RpcClientPtr db_rpc_client_;
        LoginStubms2db msl2_login_stub_;

        l2ms::LoginServiceImpl l2ms_impl_;
        g2ms::G2msServiceImpl g2ms_impl_;
        gw2ms::Gw2msServiceImpl gw2ms_impl_;        
 
        servers_info_data serverinfos_;

        common::RpcServerConnectionPtr gate_client_;
    };
}//namespace master

extern master::MasterServer* g_master_server;

#endif//MASTER_SERVER_MASTER_SERVER_H_
