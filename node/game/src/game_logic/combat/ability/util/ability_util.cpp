﻿#include "ability_util.h"

#include <muduo/base/Logging.h>

#include "ability_config.h"
#include "game_logic/combat/ability/comp/ability_comp.h"
#include "game_logic/combat/ability/constants/ability_constants.h"
#include "game_logic/scene/util/view_util.h"
#include "macros/return_define.h"
#include "pbc/ability_error_tip.pb.h"
#include "pbc/common_error_tip.pb.h"
#include "service_info/player_ability_service_info.h"
#include "thread_local/storage.h"
#include "time/comp/timer_task_comp.h"
#include "time/util/cooldown_time_util.h"

uint32_t AbilityUtil::CheckSkillActivationPrerequisites(entt::entity caster, const ::UseAbilityRequest* request) {
    auto [tableAbility, result] = ValidateAbilityTable(request->ability_id());
    if (result != kOK) {
        return result;
    }

    CHECK_RETURN_IF_NOT_OK(ValidateTarget(request));

    CHECK_RETURN_IF_NOT_OK(CheckCooldown(caster, tableAbility));

    CHECK_RETURN_IF_NOT_OK(HandleCastingTimer(caster, tableAbility));

    CHECK_RETURN_IF_NOT_OK(HandleRecoveryTimeTimer(caster, tableAbility));

    CHECK_RETURN_IF_NOT_OK(HandleChannelTimeTimer(caster, tableAbility));

    BroadcastAbilityUsedMessage(caster, request);
    SetupCastingTimer(caster, tableAbility, request->ability_id());

    return kOK;
}

bool AbilityUtil::IsAbilityOfType(uint32_t abilityId, uint32_t abilityType) {
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return false;
    }
    return std::find(tableAbility->ability_type().begin(), tableAbility->ability_type().end(), abilityType) != tableAbility->ability_type().end();
}


void AbilityUtil::HandleAbilityInitialize()
{

}

void AbilityUtil::HandleAbilitySpell(const entt::entity caster, uint32_t abilityId)
{
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return ;
    }

    for (auto& it : tableAbility->effect())
    {
        
    }
    
    HandleAbilityRecovery(caster, abilityId);
    
}

void AbilityUtil::HandleAbilityRecovery(const entt::entity caster, uint32_t abilityId)
{
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return ;
    }

    auto& recoveryTimer = tls.registry.emplace<RecoveryTimerComp>(caster).timer;
    recoveryTimer.RunAfter(tableAbility->recoverytime(), [caster, abilityId] { return HandleAbilityFinish(caster, abilityId); });
}

void AbilityUtil::HandleAbilityFinish(const entt::entity caster, uint32_t abilityId)
{

}

void AbilityUtil::HandleChannelStart(entt::entity caster, uint32_t abilityId)
{
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return ;
    }

    tls.registry.remove<ChannelFinishTimerComp>(caster);
    auto& channelFinishTimeTimer = tls.registry.emplace<ChannelFinishTimerComp>(caster).timer;
    channelFinishTimeTimer.RunAfter(tableAbility->channelfinish(),
        [caster, abilityId] { return HandleChannelFinish(caster, abilityId);} );

    tls.registry.remove<ChannelThinkIntervalTimerComp>(caster);
    auto& channelThinkIntervalTimeTimer = tls.registry.emplace<ChannelThinkIntervalTimerComp>(caster).timer;
    channelThinkIntervalTimeTimer.RunEvery(tableAbility->channelthink(),
        [caster, abilityId] { return HandleChannelThink(caster, abilityId);} );
}

void AbilityUtil::HandleChannelThink(entt::entity caster, uint32_t abilityId)
{
    
}

void AbilityUtil::HandleChannelFinish(entt::entity caster, uint32_t abilityId)
{
    tls.registry.remove<ChannelThinkIntervalTimerComp>(caster);

    HandleAbilityRecovery(caster, abilityId);
}

void AbilityUtil::HandleAbilityToggleOn(entt::entity caster, uint32_t abilityId)
{
    TriggerSkillEffect(caster, abilityId);
}

void AbilityUtil::HandleAbilityToggleOff(entt::entity caster, uint32_t abilityId)
{
    RemoveEffect(caster, abilityId);
}

void AbilityUtil::HandleAbilityActivate(entt::entity caster, uint32_t abilityId)
{
    TriggerSkillEffect(caster, abilityId);
}

void AbilityUtil::HandleAbilityDeactivate(entt::entity caster, uint32_t abilityId)
{
    RemoveEffect(caster, abilityId);
}

// 验证技能表
std::pair<const ability_row*, uint32_t> AbilityUtil::ValidateAbilityTable(uint32_t abilityId) {
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return {nullptr, kInvalidTableId};
    }
    return {tableAbility, kOK};
}

uint32_t AbilityUtil::ValidateTarget(const ::UseAbilityRequest* request) {
    const auto* tableAbility = GetAbilityTable(request->ability_id());
    if (!tableAbility->target_type().empty() && request->target_id() <= 0) {
        LOG_ERROR << "Invalid target ID: " << request->target_id() 
                 << " for ability ID: " << request->ability_id();
        return kAbilityInvalidTargetId;
    }

    if (!tableAbility->target_type().empty()) {
        entt::entity target{request->target_id()};
        if (!tls.registry.valid(target)) {
            LOG_ERROR << "Invalid target entity: " << request->target_id() 
                   << " for ability ID: " << request->ability_id();
            return kAbilityInvalidTargetId;
        }
    }
    return kOK;
}

uint32_t AbilityUtil::CheckCooldown(entt::entity caster, const ability_row* tableAbility) {
    if (const auto* coolDownTimeListComp = tls.registry.try_get<CooldownTimeListComp>(caster)) {
        if (const auto it = coolDownTimeListComp->cooldown_list().find(tableAbility->cooldown_id());
            it != coolDownTimeListComp->cooldown_list().end() &&
            CoolDownTimeMillisecondUtil::IsInCooldown(it->second)) {
            LOG_ERROR << "Ability ID: " << tableAbility->id() 
                    << " is in cooldown for player: " << entt::to_integral(caster);
            return kAbilityCooldownNotReady;
            }
    }
    return kOK;
}

uint32_t AbilityUtil::HandleCastingTimer(const entt::entity caster, const ability_row* tableAbility) {
    if (const auto* castTimerComp = tls.registry.try_get<CastingTimerComp>(caster)) {
        if (tableAbility->immediately() && castTimerComp->timer.IsActive()) {
            LOG_INFO << "Immediate ability: " << tableAbility->id() 
                     << " is currently casting. Sending interrupt message.";
            SendAbilityInterruptedMessage(caster);
            tls.registry.remove<CastingTimerComp>(caster);
            return kOK;
        }
        if (!tableAbility->immediately() && castTimerComp->timer.IsActive()) {
            LOG_ERROR << "Non-immediate ability: " << tableAbility->id() 
                      << " is currently casting and cannot be interrupted.";
            return kAbilityUnInterruptible;
        }
        tls.registry.remove<CastingTimerComp>(caster);
    }
    return kOK;
}

uint32_t AbilityUtil::HandleRecoveryTimeTimer(const entt::entity caster, const ability_row* tableAbility) {
    if (const auto* recoveryTimeTimerComp = tls.registry.try_get<RecoveryTimerComp>(caster)) {
        if (tableAbility->immediately() && recoveryTimeTimerComp->timer.IsActive()) {
            LOG_INFO << "Immediate ability: " << tableAbility->id() 
                     << " is currently casting. Sending interrupt message.";
            SendAbilityInterruptedMessage(caster);
            tls.registry.remove<RecoveryTimerComp>(caster);
            return kOK;
        }
        if (!tableAbility->immediately() && recoveryTimeTimerComp->timer.IsActive()) {
            LOG_ERROR << "Non-immediate ability: " << tableAbility->id() 
                      << " is currently casting and cannot be interrupted.";
            return kAbilityUnInterruptible;
        }
        tls.registry.remove<RecoveryTimerComp>(caster);
    }
    return kOK;
}

uint32_t AbilityUtil::HandleChannelTimeTimer(const entt::entity caster, const ability_row* tableAbility) {
    if (const auto* channelFinishTimeTimerComp = tls.registry.try_get<ChannelFinishTimerComp>(caster)) {
        if (tableAbility->immediately() && channelFinishTimeTimerComp->timer.IsActive()) {
            LOG_INFO << "Immediate ability: " << tableAbility->id() 
                     << " is currently casting. Sending interrupt message.";
            SendAbilityInterruptedMessage(caster);
            //todo 技能被打断
            tls.registry.remove<ChannelFinishTimerComp>(caster);
            return kOK;
        }
        if (!tableAbility->immediately() && channelFinishTimeTimerComp->timer.IsActive()) {
            LOG_ERROR << "Non-immediate ability: " << tableAbility->id() 
                      << " is currently casting and cannot be interrupted.";
            return kAbilityUnInterruptible;
        }
        //todo 技能被打断
        tls.registry.remove<ChannelFinishTimerComp>(caster);
    }
    return kOK;
}

void AbilityUtil::BroadcastAbilityUsedMessage(entt::entity caster, const ::UseAbilityRequest* request) {
    AbilityUsedS2C abilityUsedS2C;
    abilityUsedS2C.set_entity(entt::to_integral(caster));
    abilityUsedS2C.add_target_entity(request->target_id());
    abilityUsedS2C.set_ability_id(request->ability_id());
    abilityUsedS2C.mutable_position()->CopyFrom(request->position());

    ViewUtil::BroadcastMessageToVisiblePlayers(
        caster,
        PlayerAbilityServiceNotifyAbilityUsedMessageId,
        abilityUsedS2C
    );
}

void AbilityUtil::SetupCastingTimer(entt::entity caster, const ability_row* tableAbility, uint32_t abilityId) {
    auto& castingTimer = tls.registry.emplace<CastingTimerComp>(caster).timer;
    if (IsAbilityOfType(abilityId, kGeneralAbility)) {
        castingTimer.RunAfter(tableAbility->castpoint(), [caster, abilityId] { return HandleAbilitySpell(caster, abilityId); });
    } else if (IsAbilityOfType(abilityId, kChannelAbility)) {
        castingTimer.RunAfter(tableAbility->castpoint(), [caster, abilityId] { return HandleChannelStart(caster, abilityId); });
    }
}

// 发送技能中断消息
void AbilityUtil::SendAbilityInterruptedMessage(entt::entity caster) {
    AbilityInterruptedS2C abilityInterruptedS2C;
    abilityInterruptedS2C.set_entity(entt::to_integral(caster));
    abilityInterruptedS2C.set_ability_id(0); // todo
    ViewUtil::BroadcastMessageToVisiblePlayers(
        caster,
        PlayerAbilityServiceNotifyAbilityInterruptedMessageId,
        abilityInterruptedS2C
    );
}

void AbilityUtil::TriggerSkillEffect(entt::entity caster, uint32_t abilityId)
{
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return ;
    }

    for (auto& it : tableAbility->effect())
    {
        
    }
}

void AbilityUtil::RemoveEffect(entt::entity caster, uint32_t abilityId)
{
    const auto* tableAbility = GetAbilityTable(abilityId);
    if (tableAbility == nullptr) {
        LOG_ERROR << "Ability table not found for ID: " << abilityId;
        return ;
    }

    for (auto& it : tableAbility->effect())
    {
        
    }
}
