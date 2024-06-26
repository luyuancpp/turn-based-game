#include "centre_player_system.h"

#include "system/scene/scene_system.h"
#include "comp/scene_comp.h"
#include "thread_local/thread_local_storage_centre.h"
#include "util/defer.h"

void CenterPlayerSystem::LeaveGame(Guid player_uid)
{
    //todo 登录的时候leave
    //todo 断线不能马上下线，这里之后会改
    //没进入场景，只是登录，或者切换场景过程中
    defer(tls_cl.player_list().erase(player_uid));
    const auto player = tls_cl.get_player(player_uid);
    if (!tls.registry.valid(player))
    {
        return;
    }
    if (nullptr == tls.registry.try_get<SceneEntity>(player))
    {
    }
    else
    {
        ScenesSystem::LeaveScene({ player });
    }
}

