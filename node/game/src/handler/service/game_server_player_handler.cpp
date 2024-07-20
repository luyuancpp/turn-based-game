#include "game_server_player_handler.h"
#include "thread_local/storage.h"
#include "system/network/message_system.h"
///<<< BEGIN WRITING YOUR CODE

#include "muduo/base/Logging.h"

#include "system/player/player_node.h"

#include "proto/logic/component/player_login_comp.pb.h"
///<<< END WRITING YOUR CODE
void GamePlayerServiceHandler::Centre2GsLogin(entt::entity player,
	const ::Centre2GsLoginRequest* request,
	::google::protobuf::Empty* response)
{
	///<<< BEGIN WRITING YOUR CODE
	if (request->enter_gs_type() == LOGIN_NONE)//登录，不是普通切换场景
	{
		return;
	}
	PlayerNodeSystem::OnPlayerLogin(player, request->enter_gs_type());
	///<<< END WRITING YOUR CODE
}

