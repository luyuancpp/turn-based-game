#include "thread_local_storage_common_logic.h"

thread_local ThreadLocalStorageCommonLogic cl_tls;

entt::entity ThreadLocalStorageCommonLogic::get_player(Guid player_uid)
{
    auto player_it = players_list_.find(player_uid);
    if (players_list_.end() == player_it)
    {
        return entt::null;
    }
    return player_it->second;
}
