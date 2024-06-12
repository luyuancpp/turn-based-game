#include "player_scene_system.h"

#include "muduo/base/Logging.h"

#include "thread_local/thread_local_storage_common_logic.h"
#include "system/scene/scene_system.h"
#include "network/message_system.h"
#include "system/game_scene_system.h"

void PlayerSceneSystem::EnterScene(entt::entity player, Guid scene)
{
	GameNodeSceneSystem::EnterScene({ player, entt::entity{scene} });
}

void PlayerSceneSystem::OnEnterScene(entt::entity player, entt::entity scene)
{
	
}

void PlayerSceneSystem::LeaveScene(entt::entity player)
{
	LeaveSceneParam lp;
	lp.leaver_ = player;
	GameNodeSceneSystem::LeaveScene(player);
}

