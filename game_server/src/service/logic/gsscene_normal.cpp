#include "gsscene_normal.h"
#include "src/network/rpc_closure.h"
///<<< BEGIN WRITING YOUR CODE
#include "muduo/base/Logging.h"

#include "src/comp/player_list.h"
#include "src/network/message_sys.h"

#include "logic_proto/scene_client_player.pb.h"
///<<< END WRITING YOUR CODE

///<<<rpc begin
void ServerSceneServiceImpl::UpdateCrossMainSceneInfo(::google::protobuf::RpcController* controller,
    const ::UpdateCrossMainSceneInfoRequest* request,
    ::UpdateCrossMainSceneInfoResponse* response,
    ::google::protobuf::Closure* done)
{
    AutoRecycleClosure d(done);
///<<< BEGIN WRITING YOUR CODE 
///<<< END WRITING YOUR CODE 
}

void ServerSceneServiceImpl::Ms2GsEnterScene(::google::protobuf::RpcController* controller,
    const ::Ms2GsEnterSceneRequest* request,
    ::Ms2GsEnterSceneRespone* response,
    ::google::protobuf::Closure* done)
{
    AutoRecycleClosure d(done);
///<<< BEGIN WRITING YOUR CODE 
    //顶号，或者登录
   
    auto it = g_players.find(request->player_id());
    if (it == g_players.end())
    {
        LOG_ERROR << "player not found " << request->player_id();
        return;
    }
    EnterSeceneS2C msg;//进入了gate 然后才可以开始可以给客户端发送信息了,gs消息顺序问题要注意，进入a,再进入b gs到达客户端消息的顺序不一样
    Send2Player(msg, it->second.entity());
///<<< END WRITING YOUR CODE 
}

void ServerSceneServiceImpl::Ms2GsReconnectEnterScene(::google::protobuf::RpcController* controller,
    const ::Ms2GsEnterSceneRequest* request,
    ::Ms2GsEnterSceneRespone* response,
    ::google::protobuf::Closure* done)
{
    AutoRecycleClosure d(done);
///<<< BEGIN WRITING YOUR CODE 
///<<< END WRITING YOUR CODE 
}

///<<<rpc end
