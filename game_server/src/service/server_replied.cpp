#include "server_replied.h"

#include "muduo/base/Logging.h"

#include "src/game_logic/comp/scene_comp.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/scene/scene_factories.h"
#include "src/game_logic/scene/scene.h"
#include "src/network/ms_node.h"
#include "src/network/rpc_client.h"


void ServerReplied::StartGsMasterReplied(StartGsMasterRpc replied)
{
    auto rsp = replied->s_rp_;
    for (int32_t i = 0; i < rsp->scenes_info_size(); ++i)
    {
        CreateSceneBySceneInfoP make_scene;
        make_scene.scene_info_ = std::move(rsp->scenes_info(i));
		ScenesSystem::GetSingleton().CreateSceneByGuid(make_scene);
    }
}

void ServerReplied::StartCrossGsRegionReplied(StartCrossGsRpc replied)
{
	auto rsp = replied->s_rp_;
	for (int32_t i = 0; i < rsp->scenes_info_size(); ++i)
	{
        CreateSceneBySceneInfoP make_scene;
        make_scene.scene_info_ = std::move(rsp->scenes_info(i));
        ScenesSystem::GetSingleton().CreateSceneByGuid(make_scene);
	}
}

