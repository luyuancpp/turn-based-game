#pragma once

#include "entt/src/entt/entity/registry.hpp"

#include "src/game_logic/game_registry.h"
#include "src/util/snow_flake.h"
#include "src/game_logic/scene/servernode_system.h"

#include "src/game_logic/comp/scene_comp.h"

#include "component_proto/scene_comp.pb.h"

struct EnterSceneParam
{
	entt::entity scene_{ entt::null };
	entt::entity enterer_{ entt::null };
};

struct LeaveSceneParam
{
	entt::entity leaver_{ entt::null };
};

struct CreateSceneP
{
    uint32_t scene_confid_{ 0 };
};

struct CreateSceneBySceneInfoP
{
    SceneInfo scene_info_;
};

struct CreateGsSceneP
{
    entt::entity node_{ entt::null };
    uint32_t scene_confid_{ 0 };
};

struct MoveServerScene2ServerSceneP
{
    entt::entity from_server_{ entt::null };
    entt::entity to_server_{ entt::null };
};

struct DestroySceneParam
{
    entt::entity scene_{ entt::null };
    entt::entity server_{ entt::null };
};

struct DestroyServerParam
{
    entt::entity server_{ entt::null };
};

void AddMainSceneNodeCompnent(entt::entity e);

class ScenesSystem 
{
public:
    ~ScenesSystem();//just for test clear 

    static SceneComp copy_scenes_id() { return scenes_; }
    static std::size_t scenes_size(uint32_t scene_config_id);
    static inline std::size_t scenes_size()  { return scenes_.size(); }
    static inline std::size_t scenes_map_size()  { return scenes_.size(); }
    static void set_server_squence_node_id(uint32_t node_id) { server_squence_.set_node_id(node_id); }

    static entt::entity get_scene(Guid scene_id);

    static bool HasScene(uint32_t scene_config_id);
    static bool Empty()  { return scenes_.empty(); }

    static uint32_t CheckScenePlayerSize(entt::entity scene);

    static entt::entity CreateScene(const CreateSceneP& param);
    static entt::entity CreateSceneByGuid(const CreateSceneBySceneInfoP& param);
    static entt::entity CreateScene2Gs(const CreateGsSceneP& param);

    static void DestroyScene(const DestroySceneParam& param);
    static void DestroyServer(const DestroyServerParam& param);

    static void MoveServerScene2ServerScene(const MoveServerScene2ServerSceneP& param);

    static void EnterScene(const EnterSceneParam& param);

    static void LeaveScene(const LeaveSceneParam& param);

    static void CompelToChangeScene(const CompelChangeSceneParam& param);

    static void ReplaceCrashServer(const ReplaceCrashServerParam& param);

    static void LogPlayerEnterScene(entt::entity player);
    static void LogPlayerLeaveScene(entt::entity player);
private:
	static SceneComp scenes_;
	static ServerSequence24 server_squence_;
};

