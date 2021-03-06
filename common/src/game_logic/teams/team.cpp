#include "team.h"

#include "src/game_logic/tips_id.h"
#include "src/game_logic/teams/team_event.h"
#include "src/game_logic/game_registry.h"

#include "src/game_logic/player/player_list.h"

#include "component_proto/team_comp.pb.h"

Team::Team(const CreateTeamP& param, entt::entity teamid)
    : teamid_(teamid),
      leader_id_(param.leader_id_)
{
    for (auto& it : param.members)
    {
        AddMemeber(it);
    }
}

Guid Team::first_applicant() const
{
    if (applicants_.empty())
    {
        return kInvalidGuid;
    }
    return *applicants_.begin();
}


uint32_t Team::JoinTeam(Guid  guid)
{
    if (HasTeam(guid))
    {
        return kRetTeamMemberInTeam;
    }
    if (IsFull())
    {
        return kRetTeamMembersFull;
    }
    DelApplicant(guid);
    AddMemeber(guid);
    return kRetOK;
}

uint32_t Team::LeaveTeam(Guid guid)
{
    if (!IsMember(guid))
    {
        return kRetTeamMemberNotInTeam;
    }
    bool is_leader_leave = IsLeader(guid);
    DelMemeber(guid);
    if (!members_.empty() && is_leader_leave)
    {
        OnAppointLeader(*members_.begin());
    }           
    return kRetOK;
}

uint32_t Team::KickMember(Guid current_leader, Guid  be_kick_guid)
{
    if (leader_id_ != current_leader)
    {
        return kRetTeamKickNotLeader;
    }
    if (leader_id_ == be_kick_guid)
    {
        return kRetTeamKickSelf;
    }
    if (current_leader == be_kick_guid)
    {
        return kRetTeamKickSelf;
    }
    if (!IsMember(be_kick_guid))
    {
        return kRetTeamMemberNotInTeam;
    }
    DelMemeber(be_kick_guid);
    return kRetOK;
}

uint32_t Team::AppointLeader(Guid current_leader, Guid new_leader)
{
    if (leader_id_ == new_leader)
    {
        return kRetTeamAppointSelf;
    }
    if (!IsMember(new_leader))
    {
        return kRetTeamHasNotTeamId;
    }
    if (leader_id_ != current_leader)
    {
        return kRetTeamAppointSelf;
    }
    OnAppointLeader(new_leader);
    return kRetOK;
}

void Team::OnAppointLeader(Guid guid)
{
    leader_id_ = guid;
}

uint32_t Team::DissMiss(Guid current_leader_id)
{
    if (leader_id() != current_leader_id)
    {
        return kRetTeamDismissNotLeader;
    }
    auto temp_memebers = members_;
    for (auto it : temp_memebers)
    {
        DelMemeber(it);
    }
    return kRetOK;
}

void Team::ClearApplyList()
{
    applicants_.clear();      
}

uint32_t Team::ApplyToTeam(Guid guid)
{
	if (HasTeam(guid))
	{
		return kRetTeamMemberInTeam;
	}
	if (IsFull())
	{
		return kRetTeamMembersFull;
	}
	if (applicants_.size() >= kMaxApplicantSize)
	{
		applicants_.erase(applicants_.begin());
	}
	applicants_.emplace_back(guid);
	return kRetOK;
}


uint32_t Team::DelApplicant(Guid applicant_id)
{
    auto it = std::find(applicants_.begin(), applicants_.end(), applicant_id);
    if (it != applicants_.end())
    {
        applicants_.erase(it);
    }
    return kRetOK;
}

bool Team::HasTeam(Guid guid) const
{
    auto pit = g_players->find(guid);
    if (pit == g_players->end())
    {
        return false;
    }
    return registry.any_of<TeamId>(pit->second);
}

void Team::AddMemeber(Guid guid)
{
    auto pit = g_players->find(guid);
    if (pit == g_players->end())
    {
        return;
    }
    members_.emplace_back(guid);
    registry.emplace<TeamId>(pit->second).set_team_id(entt::to_integral(teamid_));
}

void Team::DelMemeber(Guid guid)
{
    members_.erase(std::find(members_.begin(), members_.end(), guid));
    auto pit = g_players->find(guid);
    if (pit == g_players->end())
    {
        return;
    }
    registry.remove<TeamId>(pit->second);
}
