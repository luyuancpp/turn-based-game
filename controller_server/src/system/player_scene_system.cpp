#include "player_scene_system.h"

#include "muduo/base/Logging.h"

#include "src/game_logic/comp/scene_comp.h"
#include "src/game_logic/scene/scene.h"
#include "src/game_logic/scene/servernode_system.h"
#include "src/game_logic/tips_id.h"
#include "src/network/message_system.h"
#include "src/network/player_session.h"

#include "component_proto/player_login_comp.pb.h"
#include "logic_proto/scene_server_player.pb.h"
#include "gs_service.pb.h"

using GsStubPtr = std::unique_ptr<RpcStub<gsservice::GsService_Stub>>;

void PlayerSceneSystem::Send2GsEnterScene(entt::entity player)
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
    Ms2GsEnterSceneRequest enter_scene_message;

    auto p_scene_info = registry.try_get<SceneInfo>((*p_scene).scene_entity_);
    if (nullptr == p_scene_info)
    {
        LOG_ERROR << "scene info " << player_id;
        return;
    }
    enter_scene_message.set_scene_id(p_scene_info->scene_id());
    auto try_player_session = registry.try_get<PlayerSession>(player);
    if (nullptr == try_player_session)
    {
        LOG_ERROR << "player session not valid" << player_id;
        return;
    }
    enter_scene_message.set_session_id(try_player_session->session_id());
    Send2GsPlayer(enter_scene_message, player);
}


void PlayerSceneSystem::CallPlayerEnterGs(entt::entity player)
{
	auto try_player_session = registry.try_get<PlayerSession>(player);
	if (nullptr == try_player_session)
	{
		LOG_ERROR << "send enter gs player session not found" << registry.get<Guid>(player);
		return;
	}
	auto it = g_gs_nodes.find(try_player_session->gs_node_id());
	if (it != g_gs_nodes.end())
	{
		gsservice::EnterGsRequest message;
		message.set_player_id(registry.get<Guid>(player));
		message.set_session_id(try_player_session->session_id());
		message.set_controller_node_id(controller_node_id());
		registry.get<GsStubPtr>(it->second)->CallMethod(message, &gsservice::GsService_Stub::EnterGs);
	}
}