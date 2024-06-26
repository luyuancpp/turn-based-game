#include "node_scene_system.h"

#include <ranges>

#include "comp/server_comp.h"
#include "thread_local/thread_local_storage.h"

#include "component_proto/gs_node_comp.pb.h"

using GameNodePlayerInfoPtr = std::shared_ptr<GameNodeInfo>;

//从人数少的服务器中找到一个对应场景人数最少的,效率有些低
template <typename ServerType>
entt::entity GetSceneOnMinPlayerSizeNodeT(const GetSceneParam& param, const GetSceneFilterParam& filter_state_param)
{
	auto scene_config_id = param.scene_conf_id_;
	entt::entity node{entt::null};
	std::size_t min_server_player_size = UINT64_MAX;
	for (auto entity : tls.game_node_registry.view<ServerType>())
	{
		//如果最少人数的服务器没有这个场景咋办
		//所以优先判断有没有场景
		if (const auto& server_comp = tls.game_node_registry.get<ServerComp>(entity);
			!server_comp.IsStateNormal() ||
			server_comp.GetSceneListByConfig(scene_config_id).empty() ||
				server_comp.get_server_pressure_state() != filter_state_param.node_pressure_state_)
		{
			continue;
		}
		auto server_player_size = (*tls.game_node_registry.get<GameNodePlayerInfoPtr>(entity)).player_size();
		if (server_player_size >= min_server_player_size || server_player_size >= kMaxServerPlayerSize)
		{
			continue;
		}
		node = entity;
		min_server_player_size = server_player_size;
	}

	if (entt::null == node)
	{
		return entt::null;
	}

	entt::entity scene{entt::null};
	const auto& server_comps = tls.game_node_registry.get<ServerComp>(node);
	return server_comps.GetMinPlayerSizeSceneByConfigId(scene_config_id);
}

//选择不满人的服务器场景
template <typename ServerType>
entt::entity GetNotFullSceneT(const GetSceneParam& param, const GetSceneFilterParam& filter_state_param)
{
	auto scene_config_id = param.scene_conf_id_;
	entt::entity server{entt::null};
	for (auto entity : tls.game_node_registry.view<ServerType>())
	{
		if (const auto& server_comp = tls.game_node_registry.get<ServerComp>(entity);
			!server_comp.IsStateNormal() ||
			server_comp.GetSceneListByConfig(scene_config_id).empty() ||
				server_comp.get_server_pressure_state() != filter_state_param.node_pressure_state_)
		{
			continue;
		}
		auto server_player_size = (*tls.game_node_registry.get<GameNodePlayerInfoPtr>(entity)).player_size();
		if (server_player_size >= kMaxServerPlayerSize)
		{
			continue;
		}
		server = entity;
		break;
	}

	if (entt::null == server)
	{
		return entt::null;
	}

	entt::entity scene{entt::null};
	const auto& server_comps = tls.game_node_registry.get<ServerComp>(server);
	for (const auto& server_scenes = server_comps.GetSceneListByConfig(scene_config_id);
	     const auto& scene_it : server_scenes)
	{
		if (const auto scene_player_size = tls.scene_registry.get<ScenePlayers>(scene_it).size();
			scene_player_size >= kMaxScenePlayerSize)
		{
			continue;
		}
		scene = scene_it;
		break;
	}
	return scene;
}

entt::entity NodeSceneSystem::GetSceneOnMinPlayerSizeNode(const GetSceneParam& param)
{
	constexpr GetSceneFilterParam get_scene_filter_param;
	if (const auto scene = GetSceneOnMinPlayerSizeNodeT<MainSceneServer>(param, get_scene_filter_param); entt::null != scene)
	{
		return scene;
	}
	return GetSceneOnMinPlayerSizeNodeT<MainSceneServer>(param, get_scene_filter_param);
}

entt::entity NodeSceneSystem::GetNotFullScene(const GetSceneParam& param)
{
	GetSceneFilterParam get_scene_filter_param;
	if (const auto scene_entity = GetNotFullSceneT<MainSceneServer>(param, get_scene_filter_param); 
		entt::null != scene_entity)
	{
		return scene_entity;
	}
	get_scene_filter_param.node_pressure_state_ = NodePressureState::kPressure;
	return GetNotFullSceneT<MainSceneServer>(param, get_scene_filter_param);
}

void NodeSceneSystem::NodeEnterPressure(entt::entity node)
{
	auto* const server_comp = tls.game_node_registry.try_get<ServerComp>(node);
	if (nullptr == server_comp)
	{
		return;
	}
	server_comp->SetNodePressureState(NodePressureState::kPressure);
}

void NodeSceneSystem::NodeEnterNoPressure(entt::entity node)
{
	auto* const server_comp = tls.game_node_registry.try_get<ServerComp>(node);
	if (nullptr == server_comp)
	{
		return;
	}
	server_comp->SetNodePressureState(NodePressureState::kNoPressure);
}

void NodeSceneSystem::SetNodeState(entt::entity node, NodeState node_state)
{
	auto* const try_server_comp = tls.game_node_registry.try_get<ServerComp>(node);
	if (nullptr == try_server_comp)
	{
		return;
	}
	try_server_comp->SetNodeState(node_state);
}

