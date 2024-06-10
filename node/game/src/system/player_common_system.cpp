#include "player_common_system.h"

#include "src/thread_local/thread_local_storage_common_logic.h"
#include "src/thread_local/thread_local_storage.h"
#include "src/network/gate_node.h"
#include "src/network/message_system.h"
#include "src/network/centre_node.h"
#include "src/network/session.h"
#include "service/centre_service_service.h"
#include "service/centre_scene_server_player_service.h"
#include "src/thread_local/game_thread_local_storage.h"
#include "src/util/defer.h"

#include "component_proto/player_async_comp.pb.h"
#include "component_proto/player_comp.pb.h"
#include "component_proto/player_login_comp.pb.h"
#include "component_proto/player_network_comp.pb.h"
#include "common_proto/centre_service.pb.h"
#include "src/comp/player_comp.h"

void PlayerCommonSystem::OnAsyncLoadPlayerDb(Guid player_id, player_database& message)
{
	auto async_it = game_tls.async_player_data().find(player_id);
	if (async_it == game_tls.async_player_data().end())
	{
		LOG_INFO << "player disconnect" << player_id;
		return;
	}

	defer(game_tls.async_player_data().erase(player_id));

	auto player = tls.registry.create();
	auto ret = cl_tls.player_list().emplace(player_id, player);
	if (!ret.second)
	{
		LOG_ERROR << "server emplace error" << player_id;
		return;
	}
	// on loaded db
	tls.registry.emplace<Player>(player);
	tls.registry.emplace<Guid>(player, player_id);
	tls.registry.emplace<Vector3>(player, message.pos());
	tls.registry.emplace<PlayerNodeInfo>(player);
	// on load db complete

	EnterGs(player, async_it->second);
}

void PlayerCommonSystem::OnAsyncSavePlayerDb(Guid player_id, player_database& message)
{
	//告诉Centre 保存完毕，可以切换场景了
	CentreLeaveSceneAsyncSavePlayerCompleteRequest save_complete_message;
	Send2CentrePlayer(CentreScenePlayerServiceLeaveSceneAsyncSavePlayerCompleteMsgId, save_complete_message, player_id);
    
	defer(cl_tls.player_list().erase(player_id));
    Destroy(tls.registry, cl_tls.get_player(player_id));

	//存储完毕从gs删除玩家
}

void PlayerCommonSystem::SavePlayer(entt::entity player)
{
	using SaveMessagePtr = PlayerDataRedisSystemPtr::element_type::MessageValuePtr;
	SaveMessagePtr pb = std::make_shared<SaveMessagePtr::element_type>();

	pb->set_player_id(tls.registry.get<Guid>(player));
	pb->mutable_pos()->CopyFrom(tls.registry.get<Vector3>(player));

	game_tls.player_data_redis_system()->Save(pb, tls.registry.get<Guid>(player));
}

//考虑: 没load 完再次进入别的gs
void PlayerCommonSystem::EnterGs(const entt::entity player, const EnterGsInfo& enter_info)
{
	auto* player_node_info = tls.registry.try_get<PlayerNodeInfo>(player);
	if (nullptr == player_node_info)
	{
		LOG_ERROR << "player node info  not found" << enter_info.centre_node_id();
		player_node_info = &tls.registry.emplace<PlayerNodeInfo>(player);
	}
	player_node_info->set_centre_node_id(enter_info.centre_node_id());
	//todo Centre 重新启动以后
	EnterGameNodeSucceedRequest request;
	request.set_player_id(tls.registry.get<Guid>(player));
	request.set_game_node_id(get_gate_node_id());
	CallCentreNodeMethod(CentreServiceEnterGsSucceedMsgId, request, enter_info.centre_node_id());
	//todo gs更新了对应的gate之后 然后才可以开始可以给客户端发送信息了, gs消息顺序问题要注意，
	//进入gamenode a, 再进入gamenode b 两个gs的消息到达客户端消息的顺序不一样,所以说game 还要通知game 还要收到gate 的处理完准备离开game的消息
	//否则两个不同的gs可能离开场景的消息后于进入场景的消息到达客户端
}

void PlayerCommonSystem::LeaveGs(entt::entity player)
{
	//todo
}

void PlayerCommonSystem::OnPlayerLogin(entt::entity player, uint32_t enter_gs_type)
{
	//第一次登录
	if (enter_gs_type == LOGIN_FIRST)
	{
	}
	else if (enter_gs_type == LOGIN_REPLACE)
	{
	}
	else if (enter_gs_type == LOGIN_RECONNET)//重连
	{
	}
}

void PlayerCommonSystem::OnGateUpdateGameNodeSucceed(entt::entity player)
{

}

//todo 检测
void PlayerCommonSystem::RemovePlayerSession(const Guid player_id)
{
	RemovePlayerSession(entt::entity{player_id});
}

void PlayerCommonSystem::RemovePlayerSession(entt::entity player)
{
	auto* const player_node_info = tls.registry.try_get<PlayerNodeInfo>(player);
	if (nullptr == player_node_info)
	{
		return;
	}
	player_node_info->set_gate_session_id(kInvalidSessionId);
	Destroy(tls.gate_node_registry, entt::entity{player_node_info->gate_session_id()});
}