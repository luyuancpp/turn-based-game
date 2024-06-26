#pragma once

#include "entt/src/entt/entity/registry.hpp"

#include "type_define/type_define.h"

class PlayerSceneSystem
{
public:
    static void OnLoginEnterScene(entt::entity player);
    static void Send2GsEnterScene(entt::entity player);
    static void CallPlayerEnterGs(entt::entity player, NodeId node_id);
    static void TryEnterNextScene(entt::entity player);
    static uint32_t GetDefaultSceneConfigId();
};
