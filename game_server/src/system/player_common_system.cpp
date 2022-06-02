#include "player_common_system.h"

#include "src/comp/player_list.h"
#include "src/game_logic/game_registry.h"
#include "src/network/gate_session.h"
#include "src/network/gate_node.h"
#include "src/network/ms_node.h"
#include "src/network/rpc_stub.h"
#include "src/network/session.h"

#include "component_proto/player_async_comp.pb.h"
#include "component_proto/player_login_comp.pb.h"
#include "ms_service.pb.h"

PlayerDataRedisSystemPtr g_player_data_redis_system;

std::unordered_map<uint64_t, EntityPtr> g_async_player_data;

void PlayerCommonSystem::OnAsyncLoadPlayerDatabase(Guid player_id, player_database& message)
{
    auto async_it = g_async_player_data.find(player_id);
    if (async_it == g_async_player_data.end())
    {
		LOG_INFO << "player disconnect" << player_id;
		return;
    }
    auto ret = g_players.emplace(player_id, EntityPtr());
	if (!ret.second)
	{
		LOG_ERROR << "server emplace error" << player_id;
		return;
	}
    // on loaded db
    entt::entity player = ret.first->second;
    registry.emplace<Guid>(player, player_id);
    registry.emplace<Vector3>(player, message.pos());
   	
    // on load db complete


    EnterGs(player, registry.get<EnterGsInfo>(async_it->second));
    g_async_player_data.erase(async_it);
}

void PlayerCommonSystem::EnterGs(entt::entity player, const EnterGsInfo& enter_info)
{
	auto msit = g_ms_nodes.find(enter_info.ms_node_id());
	if (msit == g_ms_nodes.end())
	{
		LOG_ERROR << " gate not found" << enter_info.ms_node_id();
		return;
	}
	registry.emplace_or_replace<MsNodePtr>(player, msit->second);//todo master 重新启动以后
	msservice::EnterGsSucceedRequest message;
	message.set_player_id(registry.get<Guid>(player));

	auto& ms_stub = registry.get<RpcStub<msservice::MasterNodeService_Stub>>(msit->second->ms_);
	ms_stub.CallMethod(message, &msservice::MasterNodeService_Stub::EnterGsSucceed);
	//todo进入了gate 然后才可以开始可以给客户端发送信息了, gs消息顺序问题要注意，进入a, 再进入b gs到达客户端消息的顺序不一样
}

void PlayerCommonSystem::OnPlayerLogin(entt::entity player, uint32_t enter_gs_type)
{
	//第一次登录
	if (enter_gs_type == LOGIN_FIRST)
	{
	}
	else if (enter_gs_type == LOGIN_REPLACE)//顶号
	{
	}
	else if (enter_gs_type == LOGIN_RECONNET)//重连
	{
	}
}

