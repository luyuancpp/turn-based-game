#include "player_tip_system.h"

#include "src/comp/player_list.h"
#include "src/constants/tips_id.h"
#include "src/network/message_system.h"
#include "service/common_client_player_service.h"
#include "src/thread_local/centre_thread_local_storage.h"
#include "src/thread_local/thread_local_storage.h"


void PlayerTipSystem::Tip(entt::entity player, uint32_t tip_id, const StringVector& str_param)
{
	TipS2C message;
	message.mutable_tips()->set_id(tip_id);
	for (auto& it : str_param)
	{
		*message.mutable_tips()->mutable_param()->Add() = it;
	}	
	Send2Player(ClientPlayerCommonServicePushTipS2CMsgId, message, player);
}

void PlayerTipSystem::Tip(Guid player_id, uint32_t tip_id, const StringVector& str_param)
{
	auto eid = entt::entity{ player_id };
    if (!tls.player_registry.valid(eid))
	{
		return;
	}
	Tip(eid, tip_id, str_param);
}