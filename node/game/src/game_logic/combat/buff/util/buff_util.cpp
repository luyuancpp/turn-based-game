﻿#include "buff_util.h"
#include "common_error_tip.pb.h"
#include "buff_config.h"
#include <muduo/base/Logging.h>
#include "game_logic/combat/buff/comp/buff_comp.h"
#include "thread_local/storage.h"
#include "buff_error_tip.pb.h"

uint32_t BuffUtil::CanCreateBuff(entt::entity parent, uint32_t buffTableId) {
    auto [tableBuff, result] = ValidateBuffTable(buffTableId);
    if (result != kOK) {
        return result;
    }

    // 1. 检查是否已经存在相同类型的Buff
    for (const auto& [id, buff] : tls.registry.get<BuffListComp>(parent).buffList) {
        auto [currentBuff, result] = ValidateBuffTable(buffTableId);
        if (result != kOK) {
            return result;
        }

        // 已存在相同类型的Buff，层数太大无法再叠加了
        if (currentBuff->id() == tableBuff->id()) {
            if (buff.layer() >= currentBuff->maxlayer())
            {
                return kBuffMaxBuffStack;
            }
            break;
        }
    }

    // 2. 检查是否免疫
    for (const auto& [id, buff] : tls.registry.get<BuffListComp>(parent).buffList) {
        auto [currentBuff, result] = ValidateBuffTable(buffTableId);
        if (result != kOK) {
            return result;
        }

        // 已存在相同类型的Buff，层数太大无法再叠加了
        if (currentBuff->immunetag() == tableBuff->tag()) {
            return kBuffTargetImmuneToBuff;
        }
    }
 
    // 3. 其他检查条件
    // ...

    return kOK; // 可以创建
}

void BuffUtil::OnBuffAwake()
{

}

void BuffUtil::OnBuffStart()
{

}

void BuffUtil::OnBuffRefresh()
{

}

void BuffUtil::OnBuffRemove()
{

}

void BuffUtil::OnBuffDestroy()
{

}

void BuffUtil::StartIntervalThink()
{

}

void BuffUtil::ApplyMotion()
{

}

void BuffUtil::OnMotionUpdate()
{

}

void BuffUtil::OnMotionInterrupt()
{

}

void BuffUtil::OnAbilityExecuted(entt::entity parent)
{

}

void BuffUtil::OnBeforeGiveDamage(entt::entity parent)
{

}

void BuffUtil::OnAfterGiveDamage(entt::entity parent)
{

}

void BuffUtil::OnBeforeTakeDamage(entt::entity parent)
{

}

void BuffUtil::OnAfterTakeDamage(entt::entity parent)
{

}

void BuffUtil::OnBeforeDead(entt::entity parent)
{

}

void BuffUtil::OnAfterDead(entt::entity parent)
{

}

void BuffUtil::OnKill(entt::entity parent)
{

}

std::pair<const buff_row*, uint32_t> BuffUtil::ValidateBuffTable(uint32_t buffTableId)
{
    const auto* tableBuff = GetBuffTable(buffTableId);
    if (tableBuff == nullptr) {
        LOG_ERROR << "Buff table not found for ID: " << buffTableId;
        return { nullptr, kInvalidTableId };
    }
    return { tableBuff, kOK };
}
