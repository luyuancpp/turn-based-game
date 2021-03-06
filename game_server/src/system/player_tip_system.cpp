#include "player_tip_system.h"

#include "src/comp/player_list.h"
#include "src/game_logic/tips_id.h"
#include "src/network/message_system.h"

#include "src/pb/pbc/logic_proto/common_client_player.pb.h"

void PlayerTipSystem::Tip(entt::entity player, uint32_t tip_id, const StringVector& str_param)
{
	TipsS2C message;
	message.mutable_tips()->set_id(tip_id);
	for (auto& it : str_param)
	{
		*message.mutable_tips()->mutable_param()->Add() = it;
	}	
	Send2Player(message, player);
}

void PlayerTipSystem::Tip(Guid player_id, uint32_t tip_id, const StringVector& str_param)
{
	auto it = g_players->find(player_id);
	if (it == g_players->end())
	{
		return;
	}
	Tip(it->second, tip_id, str_param);
}