#include "gsscene_server_player.h"
#include "src/game_logic/game_registry.h"
#include "src/network/message_sys.h"
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE

namespace serverplayer{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE

///<<<rpc begin
void PlayerServerPlayerSceneServiceImpl::LoginMs2Gs(common::EntityPtr& entity,
    const serverplayer::Ms2GsLoginRequest* request,
    ::google::protobuf::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE LoginMs2Gs
///<<< END WRITING YOUR CODE LoginMs2Gs
}

///<<<rpc end
void PlayerServerPlayerSceneServiceImpl::LoginGs2Ms(common::EntityPtr& entity,
    const serverplayer::Gs2MsLoginRequest* request,
    ::google::protobuf::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE LoginGs2Ms
///<<< END WRITING YOUR CODE LoginGs2Ms
}

///<<<rpc end
void PlayerServerPlayerSceneServiceImpl::ReconnectMs2Gs(common::EntityPtr& entity,
    const serverplayer::Ms2GsReconnectRequest* request,
    ::google::protobuf::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE ReconnectMs2Gs
///<<< END WRITING YOUR CODE ReconnectMs2Gs
}

///<<<rpc end
}// namespace serverplayer
