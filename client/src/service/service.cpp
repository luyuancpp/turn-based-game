#include "service.h"

#include "muduo/base/CountDownLatch.h"
#include "muduo/base/Logging.h"

#include "src/luacpp/lua_module.h"
#include "src/pb/pbc/msgmap.h"

using namespace common;
using namespace c2gw;

ClientService::ClientService(ProtobufDispatcher& dispatcher,
                             ProtobufCodec& codec, 
                             TcpClient& client) : codec_(codec), 
                                                  client_(client),
                                                  dispatcher_(dispatcher)
{
    dispatcher_.registerMessageCallback<LoginResponse>(
        std::bind(&ClientService::OnLoginReplied, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<CreatePlayerResponse>(
        std::bind(&ClientService::OnCreatePlayerReplied, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<EnterGameResponse>(
        std::bind(&ClientService::OnEnterGameReplied, this, _1, _2, _3));
    dispatcher_.registerMessageCallback<LeaveGameResponse>(
        std::bind(&ClientService::OnLeaveGameReplied, this, _1, _2, _3));
}

void ClientService::Send(const google::protobuf::Message& message)
{
    RpcClientMessage rpcmessage;
    rpcmessage.set_id(++id_);
    rpcmessage.set_request(message.SerializeAsString());
    rpcmessage.set_method("c2gw.C2LService");
    rpcmessage.set_msg_id(g_msgid[message.GetDescriptor()->full_name()]);    
    rpcmessage.set_service(g_idservice[rpcmessage.msg_id()]);
    rpcmessage.set_service(g_idmsg[rpcmessage.msg_id()]);
    codec_.send(conn_, rpcmessage);
}

void ClientService::OnConnection(const muduo::net::TcpConnectionPtr& conn)
{
    conn_ = conn;
}

void ClientService::ReadyGo()
{
    g_lua["LoginRequest"]["Send"] = [this](LoginRequest& request) ->void
    {
        this->codec_.send(this->conn_, request);
    };
    g_lua["ReadyGo"]();
}

void ClientService::OnLoginReplied(const muduo::net::TcpConnectionPtr& conn, 
                                   const LoginResponsePtr& message, 
                                   muduo::Timestamp)
{
    if (message->players().empty())
    {        
        g_lua["CreatePlayerRequest"]["Send"] = [this](CreatePlayerRequest& request) ->void
        {
            this->codec_.send(this->conn_, request);
        };
        g_lua["CreatePlayer"]();
        return;
    }
    EnterGame(message->players(0).guid());   
}

void ClientService::OnCreatePlayerReplied(const muduo::net::TcpConnectionPtr& conn, 
    const CreatePlayerResponsePtr& message,
    muduo::Timestamp)
{
    EnterGame(message->players(0).guid());
}

void ClientService::OnEnterGameReplied(const muduo::net::TcpConnectionPtr& conn, 
    const EnterGameResponsePtr& message,
    muduo::Timestamp)
{
    g_lua["LeaveGameRequest"]["Send"] = [this](LeaveGameRequest& request) ->void
    {
        this->codec_.send(this->conn_, request);
    };
    g_lua["LeaveGame"]();
}

void ClientService::OnLeaveGameReplied(const muduo::net::TcpConnectionPtr& conn, 
    const LeaveGameResponsePtr& message, 
    muduo::Timestamp)
{
    timer_task_.RunAfter(1, std::bind(&ClientService::DisConnect, this));
}

void ClientService::EnterGame(Guid guid)
{
    g_lua["EnterGameRequest"]["Send"] = [this](EnterGameRequest& request) ->void
    {
        this->codec_.send(this->conn_, request);
    };
    g_lua["EnterGame"](guid);
}

void ClientService::DisConnect()
{
    client_.disconnect();
}

