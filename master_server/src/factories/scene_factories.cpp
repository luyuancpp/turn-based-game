#include "scene_factories.hpp"

namespace master
{
    void OnAddScene(entt::registry& reg,
        entt::entity scene_map_entity,
        entt::entity scene_entity)
    {
        auto p_scene_entity = reg.try_get<common::SceneConfigId>(scene_entity);
        if (nullptr == p_scene_entity)
        {
            return;
        }
        uint32_t scene_config_id = p_scene_entity->scene_config_id_;
        auto& c = reg.get<common::Scenes>(scene_map_entity);
        c.scenes_group_[scene_config_id].emplace(scene_entity);
        c.scenes_.emplace(scene_entity);
    }

    entt::entity MakeScenes(entt::registry& reg)
    {
        auto e = reg.create();
        reg.emplace<common::Scenes>(e);
        return e;
    }

    entt::entity MakeMainScene(entt::registry& reg,
        const MakeSceneParam& param)
    {
        auto e = reg.create();
        reg.emplace<common::SceneConfigId>(e, param.scene_config_id_);
        reg.emplace<common::ScenePlayerList>(e); 
        OnAddScene(reg, param.scene_map_entity_, e);
        return e;
    }

    entt::entity MakeGameServer(entt::registry& reg,
        const MakeGameServerParam& param)
    {
        auto e = reg.create();
        common::GameServerDataPtr p_server_data = std::make_shared<common::GameServerData>();
        p_server_data->server_id_ = param.server_id_;
        p_server_data->server_entity_ = e;
        reg.emplace<common::GameServerDataPtr>(e, p_server_data);
        reg.emplace<common::SceneIds>(e);
        return e;
    }

    entt::entity MakeScene2GameServer(entt::registry& reg, 
        const MakeScene2GameServerParam& param)
    {
        MakeSceneParam main_scene_param;
        main_scene_param.op_ = param.op_;
        main_scene_param.scene_config_id_ = param.scene_config_id_;
        main_scene_param.scene_map_entity_ = param.scene_map_entity_;
        auto e = MakeMainScene(reg, main_scene_param);
        PutScene2GameServerParam put_param;
        put_param.scene_entity_ = e;
        put_param.server_entity_ = param.server_entity_;
        PutScene2GameServer(reg, put_param);
        return e;
    }

    void PutScene2GameServer(entt::registry& reg, 
        const PutScene2GameServerParam& param)
    {
        auto scene_entity = param.scene_entity_;
        if (nullptr ==  reg.try_get<common::SceneConfigId>(scene_entity))
        {
            return;
        }
        auto server_entity = param.server_entity_;
        auto& server_ids = reg.get<common::SceneIds>(server_entity);
        server_ids.emplace(scene_entity);
        auto& p_server_data = reg.get<common::GameServerDataPtr>(server_entity);
        reg.emplace<common::GameServerDataPtr>(scene_entity, p_server_data);
    }

    void DestroyScene(entt::registry& reg,
        const RemoveSceneParam& param)
    {

    }

}//namespace master