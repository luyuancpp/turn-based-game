#pragma once
#include "src/pb/pbc/logic_proto/scene_normal.pb.h"
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
class ServerSceneServiceImpl : public normal::ServerSceneService{
public:
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
public:
    void UpdateCrossMainSceneInfo(::google::protobuf::RpcController* controller,
        const normal::UpdateCrossMainSceneInfoRequest* request,
        normal::UpdateCrossMainSceneInfoResponse* response,
        ::google::protobuf::Closure* done)override;

};