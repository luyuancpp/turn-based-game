#include "player_tip_util.h"

#include "game_logic/network//message_util.h"
#include "service/common_client_player_service.h"
#include "thread_local/storage_common_logic.h"

void PlayerTipUtil::SendToPlayer(entt::entity playerEntity, uint32_t tipId, const StringVector& parameters)
{
	TipInfoMessage message;
	message.mutable_tip_info()->set_id(tipId);
	for (auto& param : parameters)
	{
		*message.mutable_tip_info()->mutable_parameters()->Add() = param;
	}
	::SendMessageToPlayer(ClientPlayerCommonServiceSendTipToClientMsgId, message, playerEntity);
}

void PlayerTipUtil::SendToPlayer(Guid playerId, uint32_t tipId, const StringVector& parameters)
{
	const auto playerIterator = tlsCommonLogic.GetPlayerList().find(playerId);
	if (playerIterator == tlsCommonLogic.GetPlayerList().end())
	{
		return;
	}
	SendToPlayer(playerIterator->second, tipId, parameters);
}
