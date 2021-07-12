#ifndef LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_
#define LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_

#include "l2ms.pb.h"

#include "src/rpc_closure_param/rpc_stub1.h"
#include "src/rpc_closure_param/rpc_stub_client1.h"

using namespace muduo;
using namespace muduo::net;

namespace login
{
    class MasterRpcClient : noncopyable
    {
    public:
        using RpcClientPtr = std::unique_ptr<common::RpcClient1>;

        static RpcClientPtr& GetSingleton()
        {
            static RpcClientPtr singleton;
            return singleton;
        }

        static void Connect(EventLoop* loop,
            const InetAddress& login_server_addr)
        {
            GetSingleton() = std::make_unique<common::RpcClient1>(loop, login_server_addr);
            GetSingleton()->connect();
        }
    };

    class MasterLoginRpcStub : noncopyable
    {
    public:
        using RpcStub = common::RpcStub1<l2ms::LoginService_Stub>;
        static RpcStub& GetSingleton()
        {
            static RpcStub singleton(*MasterRpcClient::GetSingleton());
            return singleton;
        }
    };

}// namespace login

#endif // LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_

