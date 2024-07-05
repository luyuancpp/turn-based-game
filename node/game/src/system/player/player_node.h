#pragma once

#include "redis_client/redis_client.h"

#include "common_proto/mysql_database_table.pb.h"

using PlayerRedis = std::unique_ptr<MessageAsyncClient<Guid, player_database>>;

class EnterGsInfo;

class PlayerNodeSystem
{
public:
	//如果异步加载过程中玩家断开链接了？会不会造成数据覆盖
	static void OnPlayerAsyncLoaded(Guid player_id, const player_database& message);
	static void OnPlayerAsyncSaved(Guid player_id, player_database& message);
	static void SavePlayer(entt::entity player);
	static void EnterGs(const entt::entity player, const EnterGsInfo& enter_info);
	static void LeaveGs(entt::entity player);
	static void OnPlayerLogin(entt::entity player, uint32_t enter_gs_type);
	static void OnRegister2GatePlayerGameNode(entt::entity player);
	static void RemovePlayerSession(Guid player_id);
	static void RemovePlayerSession(entt::entity player);
	static  void DestroyPlayer(Guid player_id);
};
