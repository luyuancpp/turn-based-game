#ifndef MASTER_SRC_FACTORIES_SCENE_FACTORIES_HPP_
#define MASTER_SRC_FACTORIES_SCENE_FACTORIES_HPP_

#include "entt/src/entt/entity/registry.hpp"

#include "src/game_logic/comp/gs_scene_comp.hpp"

namespace master
{
struct MakeSceneParam
{
    uint32_t scene_config_id_{ 0 };
    uint32_t op_{ 0 };
};

struct MakeGameServerParam
{
    uint32_t node_id_{};
    uint32_t op_{ 0 };
};

struct MakeScene2GameServerParam
{
    entt::entity server_entity_{ entt::null };
    uint32_t scene_config_id_{ 0 };
    uint32_t op_{ 0 };
};

struct PutScene2GameServerParam
{
    entt::entity scene_entity_{ entt::null };
    entt::entity server_entity_{ entt::null };
    uint32_t op_{ 0 };
};

struct MoveServerScene2ServerParam
{
    entt::entity from_server_entity_{ entt::null };
    entt::entity to_server_entity_{ entt::null };
    uint32_t op_{ 0 };
};

struct DestroySceneParam
{
    entt::entity scene_entity_{ entt::null };
};

struct DestroyServerParam
{
    entt::entity server_entity_{ entt::null };
};

entt::entity& scenes_entity();

void MakeScenes();

entt::entity MakeMainScene(entt::registry& reg, const MakeSceneParam& param);

entt::entity MakeMainSceneGameServer(entt::registry& reg, const MakeGameServerParam& param);

}//namespace master

#endif//MASTER_SRC_FACTORIES_SCENE_FACTORIES_HPP_
