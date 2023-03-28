#pragma once

#include "src/game_logic/thread_local/thread_local_storage.h"

#include "src/common_type/common_type.h"

static const std::size_t kMaxServerPlayerSize = 2000;
static const std::size_t kMaxScenePlayerSize = 1000;

struct GetSceneParam
{
	uint32_t scene_confid_{ 0 };
};

struct ServerPressureParam
{
    entt::entity server_{ entt::null };
};

struct ServerCrashParam
{
    entt::entity crash_server_{ entt::null };
};

struct ReplaceCrashServerParam
{
    entt::entity cransh_server_{ entt::null };
    entt::entity replace_server_{ entt::null };
};

struct MaintainServerParam
{
    entt::entity maintain_server_{ entt::null };
};

struct CompelChangeSceneParam
{
    entt::entity player_{ entt::null };
    entt::entity new_server_{ entt::null };
    uint32_t scene_confid_{0};
};

class ServerNodeSystem
{
public:

    static ServerNodeSystem& GetSingleton() { static ServerNodeSystem singleton; return singleton; }

	static entt::entity GetWeightRoundRobinMainScene(const GetSceneParam& param);

    static  entt::entity GetWeightRoundRobinRoomScene(const GetSceneParam& param);

    static  entt::entity GetMainSceneNotFull(const GetSceneParam& param);

    static  void ServerEnterPressure(const ServerPressureParam& param);

    static  void ServerEnterNoPressure( const ServerPressureParam& param);

    static  void ServerCrashed(const ServerCrashParam& param);

    static  void ServerMaintain(const MaintainServerParam& param);
};

