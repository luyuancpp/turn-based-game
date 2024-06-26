#pragma once

#include "entt/src/entt/entity/registry.hpp"

#include "type_define/type_define.h"

class PlayerTipSystem
{
public:
    static void Tip(entt::entity player, uint32_t tip_id, const StringVector& str_param);
    static void Tip(Guid player_id, uint32_t tip_id, const StringVector& str_param);
};
