#pragma once
#include "game_service.pb.h"
class GameServiceImpl : public ::GameService{
public:
public:
    void EnterGs(::google::protobuf::RpcController* controller,
        const ::GameNodeEnterGsRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

    void Send2Player(::google::protobuf::RpcController* controller,
        const ::NodeServiceMessageRequest* request,
        ::NodeServiceMessageResponse* response,
        ::google::protobuf::Closure* done)override;

    void ClientSend2Player(::google::protobuf::RpcController* controller,
        const ::GameNodeRpcClientRequest* request,
        ::GameNodeRpcClientResponse* response,
        ::google::protobuf::Closure* done)override;

    void Disconnect(::google::protobuf::RpcController* controller,
        const ::GameNodeDisconnectRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

    void GateConnectGs(::google::protobuf::RpcController* controller,
        const ::GameNodeConnectRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

    void ControllerSend2PlayerViaGs(::google::protobuf::RpcController* controller,
        const ::NodeServiceMessageRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

    void CallPlayer(::google::protobuf::RpcController* controller,
        const ::NodeServiceMessageRequest* request,
        ::NodeServiceMessageResponse* response,
        ::google::protobuf::Closure* done)override;

};