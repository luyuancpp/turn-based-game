#ifndef GAME_SERVER_SRC_GAME_SERVER_GAME_SERVER_H_
#define GAME_SERVER_SRC_GAME_SERVER_GAME_SERVER_H_

#include "muduo/net/TcpServer.h"
#include "muduo/net/EventLoop.h"

#include "src/service/gs_node.h"
#include "src/service/rg2gs.h"
#include "src/server_common/deploy_rpcclient.h"
#include "src/server_common/rpc_server.h"
#include "src/server_common/rpc_stub.h"
#include "src/redis_client/redis_client.h"
#include "src/server_common/rpc_closure.h"

#include "ms_node.pb.h"
#include "gs2rg.pb.h"

namespace game
{
using MasterSessionPtr = std::shared_ptr<common::RpcClient>;

class GameServer : muduo::noncopyable, public common::Receiver<GameServer>
{
public:
    using RedisClientPtr = common::RedisClientPtr;
    using RpcServerPtr = std::shared_ptr<muduo::net::RpcServer>;
    using StubMsNode = common::RpcStub<msservice::MasterNodeService_Stub>;
    using StubG2rg = common::RpcStub<gs2rg::G2rgService_Stub>;

    GameServer(muduo::net::EventLoop* loop);

    void Init();

    void InitNetwork();

    using ServerInfoRpcClosure = common::NormalClosure<deploy::ServerInfoRequest,
        deploy::ServerInfoResponse>;
    using ServerInfoRpcRC = std::shared_ptr<ServerInfoRpcClosure>;
    void ServerInfo(ServerInfoRpcRC cp);

    using StartGSInfoRpcClosure = common::NormalClosure<deploy::StartGSRequest,
        deploy::StartGSResponse>;
    using StartGSRpcRC = std::shared_ptr<StartGSInfoRpcClosure>;
    void StartGSDeployReplied(StartGSRpcRC cp);

    void Register2Master(MasterSessionPtr& master_rpc_client);

    void receive(const common::OnConnected2ServerEvent& es);
    void receive(const common::OnBeConnectedEvent& es);

private:    
    void InitGlobalEntities();
    void InitRoomMasters(const deploy::ServerInfoResponse* resp);
    void ConnectMaster();
    void ConnectRegion();

    muduo::net::EventLoop* loop_{ nullptr };

    RedisClientPtr redis_;

    RpcServerPtr server_;

    common::RpcClientPtr deploy_session_;
    deploy::DeployStub deploy_stub_;

    StubMsNode g2ms_stub_;

    common::RpcClientPtr region_session_;
    StubG2rg g2rg_stub_;

    ::game_server_db server_deploy_;

    rg2gs::Rg2gServiceImpl rg2g_impl_;
    gsservice::GsServiceImpl gs_service_impl_;
};

};//namespace game

extern game::GameServer* g_gs;

#endif // !GAME_SERVER_SRC_GAME_SERVER_GAME_SERVER_H_
