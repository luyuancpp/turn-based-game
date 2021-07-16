#ifndef GATEWAY_GATEWAY_SERVER_H_
#define GATEWAY_GATEWAY_SERVER_H_

#include <stdio.h>

#include "muduo/base/Logging.h"
#include "muduo/base/Mutex.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/TcpServer.h"

#include "src/codec/codec.h"
#include "src/codec/dispatcher.h"
#include "src/event/event.h"
#include "src/client/service/service.h"
#include "src/net/deploy/rpcclient/deploy_rpcclient.h"
#include "src/rpc_closure_param/rpc_closure.h"
#include "src/rpc_closure_param/rpc_connection_event.h"

using namespace muduo;
using namespace muduo::net;

namespace gateway
{
class GatewayServer : noncopyable, public common::Receiver<GatewayServer>
{
public:
    using RpcStubgw2l = common::RpcStub<gw2l::LoginService_Stub>;
    using TcpServerPtr = std::unique_ptr<TcpServer>;

    GatewayServer(EventLoop* loop)
        : loop_(loop),
        dispatcher_(std::bind(&GatewayServer::OnUnknownMessage, this, _1, _2, _3)),
        codec_(std::bind(&ProtobufDispatcher::onProtobufMessage, &dispatcher_, _1, _2, _3)),
        client_receiver_(codec_, dispatcher_, login_stub_gw2l_)
    {
        
    }

    void LoadConfig();

    void ConnectDeploy();

    void Start();

    void receive(const common::ConnectionEvent& es);

    using ServerInfoRpcClosure = common::RpcClosure<deploy::ServerInfoRequest,
        deploy::ServerInfoResponse>;
    using ServerInfoRpcRC = std::shared_ptr<ServerInfoRpcClosure>;
    void StartServer(ServerInfoRpcRC cp);

private:
    void OnConnection(const TcpConnectionPtr& conn)
    {
        client_receiver_.OnConnection(conn);
    }

    void OnUnknownMessage(const TcpConnectionPtr& conn,
        const MessagePtr& message,
        Timestamp)
    {
        LOG_INFO << "onUnknownMessage: " << message->GetTypeName();
        conn->shutdown();
    }

    muduo::net::EventLoop* loop_{ nullptr };

    ProtobufDispatcher dispatcher_;
    ProtobufCodec codec_;
    ClientReceiver client_receiver_;

    TcpServerPtr server_;

    common::RpcClientPtr deploy_rpc_client_;
    deploy::DeployRpcStub deploy_stub_;

    common::RpcClientPtr login_rpc_client_;
    RpcStubgw2l login_stub_gw2l_;
};

} // namespace gateway
 
#endif // !GATEWAY_GATEWAY_SERVER_H_


