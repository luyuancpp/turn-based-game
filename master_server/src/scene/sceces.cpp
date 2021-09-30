#include "src/scene/sceces.h"

#include "src/game_logic/game_registry.h"

using namespace common;

namespace master
{
    ScenesManager::ScenesManager()
    {
    }

    const common::SceneIds& ScenesManager::scenes_config_id(uint32_t scene_config_id) const
    {
        auto it = config_scene_.find(scene_config_id);
        if (it == config_scene_.end())
        {
            static common::SceneIds s;
            return s;
        }
        return it->second;
    }

    entt::entity ScenesManager::scene_id(uint32_t scene_config_id) const
    {
        auto it = config_scene_.find(scene_config_id);
        if (it == config_scene_.end())
        {
            return entt::null;
        }
        if (it->second.empty())
        {
            return entt::null;
        }
        return *it->second.begin();
    }

    std::size_t ScenesManager::scene_config_size(uint32_t scene_config_id)const
    {
        auto it = config_scene_.find(scene_config_id);
        if (it == config_scene_.end())
        {
            return 0;
        }
        return it->second.size();
    }

    bool ScenesManager::scene_config_empty(uint32_t scene_config_id)
    {
        auto it = config_scene_.find(scene_config_id);
        if (it == config_scene_.end())
        {
            return true;
        }
        return it->second.empty();
    }

    entt::entity ScenesManager::MakeMainScene(const MakeSceneParam& param)
    {
        auto e = reg().create();
        reg().emplace<common::SceneConfig>(e, param.scene_config_id_);
        reg().emplace<common::MainScene>(e);
        reg().emplace<common::PlayerEntities>(e);
        auto& scene_config = reg().get<common::SceneConfig>(e);
        auto scene_guid = snow_flake_.Generate();
        reg().emplace<common::GameGuid>(e, scene_guid);
        scenes_map_.emplace(scene_guid, e);
        AddScene(scene_config.scene_config_id(), e);
        return e;
    }

    entt::entity ScenesManager::MakeScene2GameServer(const MakeScene2GameServerParam& param)
    {
        MakeSceneParam main_scene_param;
        main_scene_param.op_ = param.op_;
        main_scene_param.scene_config_id_ = param.scene_config_id_;
        auto e = MakeMainScene(main_scene_param);
        PutScene2GameServerParam put_param;
        put_param.scene_entity_ = e;
        put_param.server_entity_ = param.server_entity_;
        PutScene2GameServer(put_param);
        return e;
    }

    void ScenesManager::PutScene2GameServer(const PutScene2GameServerParam& param)
    {
        auto scene_entity = param.scene_entity_;
        auto& scene_config = reg().get<common::SceneConfig>(scene_entity);
        auto server_entity = param.server_entity_;
        auto& server_scenes = reg().get<common::Scenes>(server_entity);
        server_scenes.AddScene(scene_config.scene_config_id(), scene_entity);
        auto& p_server_data = reg().get<common::GameServerDataPtr>(server_entity);
        reg().emplace<common::GameServerDataPtr>(scene_entity, p_server_data);
    }


    void ScenesManager::AddScene(uint32_t scene_config_id, entt::entity scene_entity)
    {
        config_scene_[scene_config_id].emplace(scene_entity);
        scenes_.emplace(scene_entity);
    }

    void ScenesManager::RemoveScene(uint32_t scene_config_id, entt::entity scene_entity)
    {
        config_scene_[scene_config_id].erase(scene_entity);
        scenes_.erase(scene_entity);
    }

    void ScenesManager::OnDestroyScene(entt::entity scene_entity)
    {
        auto scene_config_id = reg().get<common::SceneConfig>(scene_entity).scene_config_id();
        RemoveScene(scene_config_id, scene_entity);
        auto scene_guid = reg().get<common::GameGuid>(scene_entity);
        scenes_map_.erase(scene_guid);
        auto p_server_data = reg().get<common::GameServerDataPtr>(scene_entity);
        reg().destroy(scene_entity);
        if (nullptr == p_server_data)
        {
            return;
        }
        auto& server_scene = reg().get<common::Scenes>(p_server_data->server_entity());
        server_scene.RemoveScene(scene_config_id, scene_entity);
    }

}//namespace master