#pragma once

#include "system/redis.h"
#include "comp/scene/nav.h"

#include "common_proto/mysql_database_table.pb.h"
#include "component_proto/player_async_comp.pb.h"
#include "component_proto/frame_comp.pb.h"

using PlayerRedis = std::unique_ptr<MessageAsyncClient<Guid, player_database>>;
using PlayerEnterGSInfoList = std::unordered_map<Guid, EnterGsInfo>;

class ThreadLocalStorageGame
{
public:
	RedisSystem redis_;
	PlayerRedis player_redis_;
	PlayerEnterGSInfoList async_player_list_;
	SceneNavs scene_nav_;
	FrameTime frame_time_;
};

extern thread_local ThreadLocalStorageGame tls_game;
