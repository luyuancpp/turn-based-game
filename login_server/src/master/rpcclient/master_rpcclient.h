#ifndef LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_
#define LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_

#include "l2ms.pb.h"

#include "src/rpc_closure_param/stub_rpc_client.h"

using namespace muduo;
using namespace muduo::net;

namespace login
{
    
    class MasterRpcClient
    {
    public:
        using StubType = common::RpcClient<l2ms::LoginService_Stub>;
        using RpcClientPtr = std::unique_ptr<StubType>;

        static RpcClientPtr& GetSingleton()
        {
            static RpcClientPtr singleton;
            return singleton;
        }

        static void InitSingleton(EventLoop* loop,
            const InetAddress& login_server_addr)
        {
            GetSingleton() = std::make_unique<MasterRpcClient::StubType>(loop, login_server_addr);
        }

    };

}// namespace login

#endif // LOGIN_SERVER_SRC_MASTER_RPCCLIENT_DATABASE_RPC_CLIENT_H_

