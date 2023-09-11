#include "team.h"

#include "src/game_logic/teams/team_event.h"
#include "src/game_logic/thread_local/common_logic_thread_local_storage.h"
#include "src/game_logic/thread_local/thread_local_storage.h"
#include "src/game_logic/tips_id.h"

#include "component_proto/team_comp.pb.h"

void Team::OnAppointLeader(Guid guid)
{
    leader_id_ = guid;
}

bool Team::HasTeam(const Guid guid)
{
    const auto player_it = cl_tls.player_list().find(guid);
    if (player_it == cl_tls.player_list().end())
    {
        return false;
    }
    return tls.registry.any_of<TeamId>(player_it->second);
}

void Team::AddMember(Guid guid)
{
    auto pit = cl_tls.player_list().find(guid);
    if (pit == cl_tls.player_list().end())
    {
        return;
    }
    members_.emplace_back(guid);
    tls.registry.emplace<TeamId>(pit->second).set_team_id(entt::to_integral(team_id_));
}

void Team::DelMember(Guid guid)
{
    members_.erase(std::find(members_.begin(), members_.end(), guid));
    auto pit = cl_tls.player_list().find(guid);
    if (pit == cl_tls.player_list().end())
    {
        return;
    }
    tls.registry.remove<TeamId>(pit->second);
}
