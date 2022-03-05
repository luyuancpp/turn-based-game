#ifndef GATEWAY_SERVER_SRC_CLENT_SERVICE_SERVICE_H_
#define GATEWAY_SERVER_SRC_CLENT_SERVICE_SERVICE_H_

#include "src/server_common/codec/codec.h"

#include "muduo/base/noncopyable.h"
#include "muduo/net/EventLoop.h"

#include "src/server_common/codec/dispatcher.h"
#include "src/server_common/rpc_client_closure.h"
#include "src/server_common/rpc_stub.h"
#include "src/server_common/rpc_client.h"
#include "src/server_sequence/server_sequence.h"

#include "c2gw.pb.h"
#include "gw2gs.pb.h"
#include "gw2l.pb.h"
#include "gw2ms.pb.h"

using namespace muduo;
using namespace muduo::net;
using namespace c2gw;
using namespace gw2gs;

namespace gateway
{
using LoginRequestPtr = std::shared_ptr<LoginRequest> ;
using CreatePlayerRequestPtr = std::shared_ptr<CreatePlayerRequest>;
using EnterGameRequestPtr = std::shared_ptr<EnterGameRequest>;
using LeaveGameRequestPtr = std::shared_ptr<LeaveGameRequest>;
using RpcClientMessagePtr = std::shared_ptr<RpcClientMessage>;

class ClientReceiver : muduo::noncopyable
{
public:

    using RpcStubgw2l = common::RpcStub<gw2l::LoginService_Stub>;
    using RpcStubgw2g = common::RpcStub<gw2gs::Gw2gsService_Stub>;

    ClientReceiver(ProtobufCodec& codec, ProtobufDispatcher& dispatcher, RpcStubgw2l& gw2l_login_stub, RpcStubgw2g& gw2g_stub);

    void OnConnection(const muduo::net::TcpConnectionPtr& conn);

    //client to gateway 
    void OnLogin(const muduo::net::TcpConnectionPtr& conn,
        const LoginRequestPtr& message,
        muduo::Timestamp);

    using LoginRpcReplied = std::shared_ptr<common::ClientClosure<LoginResponse, gw2l::LoginRequest, gw2l::LoginResponse>>;
    void OnServerLoginReplied(LoginRpcReplied cp);

    void OnCreatePlayer(const muduo::net::TcpConnectionPtr& conn, 
        const CreatePlayerRequestPtr& message, 
        muduo::Timestamp);

    using CreatePlayeReplied = std::shared_ptr<common::ClientClosure<CreatePlayerResponse, gw2l::CreatePlayerRequest, gw2l::CreatePlayerResponse>>;
    void OnServerCreatePlayerReplied(CreatePlayeReplied cp);

    void OnEnterGame(const muduo::net::TcpConnectionPtr& conn,
        const EnterGameRequestPtr& message,
        muduo::Timestamp);

    using EnterGameRpcRplied = std::shared_ptr<common::ClientClosure<EnterGameResponse, gw2l::EnterGameRequest, gw2l::EnterGameResponse>>;
    void OnServerEnterGameReplied(EnterGameRpcRplied cp);

    void OnLeaveGame(const muduo::net::TcpConnectionPtr& conn,
        const LeaveGameRequestPtr& message,
        muduo::Timestamp);

	void OnRpcClientMessage(const muduo::net::TcpConnectionPtr& conn,
		const RpcClientMessagePtr& message,
		muduo::Timestamp);

	using EnterGameRpcRplied = std::shared_ptr<common::ClientClosure<EnterGameResponse, gw2l::EnterGameRequest, gw2l::EnterGameResponse>>;
	void OnRpcClientReplied(EnterGameRpcRplied cp);
private:
    ProtobufCodec& codec_;
    ProtobufDispatcher& dispatcher_;
    RpcStubgw2l& gw2l_login_stub_;
    RpcStubgw2g& gw2g_stub_;
    common::ServerSequence server_sequence_;
};
}//namespace gateway

#endif // GATEWAY_SERVER_SRC_CLENT_SERVICE_SERVICE_H_