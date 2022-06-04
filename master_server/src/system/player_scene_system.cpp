#include "player_scene_system.h"

#include "muduo/base/Logging.h"

#include "src/game_logic/comp/scene_comp.h"
#include "src/network/message_system.h"
#include "src/network/player_session.h"

#include "component_proto/player_login_comp.pb.h"
#include "logic_proto/scene_server_player.pb.h"
#include "gs_service.pb.h"

void PlayerSceneSystem::EnterScene(entt::entity player)
{
    if (entt::null == player)
    {
		LOG_ERROR << "player is null ";
		return;
    }
    auto p_scene = registry.try_get<SceneEntity>(player);
    auto player_id = registry.get<Guid>(player);
    if (nullptr == p_scene)
    {
        LOG_ERROR << "player do not enter scene " << player_id;
        return;
    }
    Ms2GsEnterSceneRequest message;
	auto try_enter_gs = registry.try_get<EnterGsComp>(player);
	if (nullptr != try_enter_gs)
	{
		message.set_enter_gs_type((*try_enter_gs).enter_gs_type());
		registry.remove<EnterGsComp>(player);
	}
    auto p_scene_info = registry.try_get<SceneInfo>((*p_scene).scene_entity());
    if (nullptr == p_scene_info)
    {
        LOG_ERROR << "scene info " << player_id;
        return;
    }
    message.mutable_scene_info()->CopyFrom(*p_scene_info);
    auto& player_session = registry.get<PlayerSession>(player);
    message.set_session_id(player_session.session_id());
    Send2GsPlayer(message, player);
}