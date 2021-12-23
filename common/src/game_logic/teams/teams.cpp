#include "teams.h"

#include "src/return_code/error_code.h"

namespace common
{
#define GetTeamPtrReturnError \
    auto e = entt::to_entity(team_id);\
    if (!reg().valid(e))\
    {\
        return RET_TEAM_HAS_NOT_TEAM_ID;\
    }\
    auto& team = reg().get<Team>(e);\

#define GetTeamEntityReturnError \
    if (!reg().valid(team_id))\
    {\
        return RET_TEAM_HAS_NOT_TEAM_ID;\
    }\
    auto& team = reg().get<Team>(team_id);\

#define GetTeamReturn(ret) \
    auto e = entt::to_entity(team_id);\
    if (!reg().valid(e))\
    {\
        return ret;\
    }\
    auto& team = reg().get<Team>(e);\

    Teams::Teams()
        : emp_(EventManager::New())
    {
        my_entity_id_ = reg().create();
        reg().emplace<PlayerTeamMap>(my_entity_id_, PlayerTeamMap());
    }

    std::size_t Teams::member_size(Guid team_id)
    {
        GetTeamReturn(0);
        return team.member_size();
    }

    std::size_t Teams::applicant_size_by_playerid(Guid guid) const
    {
        auto team_id = GetTeamId(guid);
        return applicant_size_by_team_id(team_id);
    }

    std::size_t Teams::applicant_size_by_team_id(Guid team_id) const
    {
        GetTeamReturn(0);
        return team.applicant_size();
    }

    Guid Teams::GetTeamId(Guid guid)const
    {
        auto& player_team_map_ = reg().get<PlayerTeamMap>(my_entity_id_);
        auto it = player_team_map_.find(guid);
        if (it == player_team_map_.end())
        {
            return kEmptyGuid;
        }
        return entt::to_integral(it->second);
    }

    entt::entity Teams::GetTeamEntityId(Guid guid) const
    {
        auto& player_team_map_ = reg().get<PlayerTeamMap>(my_entity_id_);
        auto it = player_team_map_.find(guid);
        if (it == player_team_map_.end())
        {
            return entt::null;
        }
        return it->second;
    }

    Guid Teams::get_leader_id_by_teamid(Guid team_id) const
    {
        GetTeamReturn(kEmptyGuid);
        return team.leader_id();
    }

    Guid Teams::get_leader_id_by_playerid(Guid guid) const
    {
        auto team_id = GetTeamId(guid);
        return get_leader_id_by_teamid(team_id);
    }
    
    Guid Teams::first_applicant(Guid team_id) const
    {
        GetTeamReturn(0);
        return team.first_applicant();
    }

    bool Teams::IsTeamFull(Guid team_id)
    {
        GetTeamReturn(false);
        return team.IsFull();
    }

    bool Teams::HasMember(Guid team_id, Guid guid)
    {
        GetTeamReturn(false);
        return team.HasMember(guid);
    }

    bool Teams::HasTeam(Guid guid) const
    {
        auto& player_team_map_ = reg().get<PlayerTeamMap>(my_entity_id_);
        return player_team_map_.find(guid) != player_team_map_.end(); 
    }

    bool Teams::HasApplicant(Guid team_id, Guid guid) const
    {
        GetTeamReturn(false);
        return team.HasApplicant(guid);
    }

    uint32_t Teams::CreateTeam(const CreateTeamP& param)
    {
        if (IsTeamsMax())
        {
            return RET_TEAM_TEAM_LIST_MAX;
        }
        if (HasTeam(param.leader_id_))
        {
            return RET_TEAM_MEMBER_IN_TEAM;
        }
        RET_CHECK_RET(CheckMemberInTeam(param.members));

        auto e = reg().create();
        TeamsP ts_param{e, my_entity_id_, emp_, &reg() };
        auto team = reg().emplace<Team>(e, param, ts_param);

        PlayerInTeamF f_in_the_team;
        f_in_the_team.cb_ = std::bind(&Teams::HasTeam, this, std::placeholders::_1);
        reg().emplace<PlayerInTeamF>(e, f_in_the_team);
        last_team_id_ = entt::to_integral(e);//for test
        return RET_OK;
    }

    uint32_t Teams::JoinTeam(Guid team_id, Guid guid)
    {
        GetTeamPtrReturnError;
        return team.JoinTeam(guid);
    }

    uint32_t Teams::JoinTeam(const UInt64Set& member_list, Guid  team_id)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(CheckMemberInTeam(member_list));
        for (auto& it : member_list)
        {
            RET_CHECK_RET(team.JoinTeam(it));
        }
        return RET_OK;
    }

    uint32_t Teams::CheckMemberInTeam(const UInt64Set& member_list)
    {
        for (auto& it : member_list)
        {
            if (HasTeam(it))
            {
                return RET_TEAM_MEMBER_IN_TEAM;
            }
        }
        return RET_OK;
    }

    uint32_t Teams::LeaveTeam(Guid guid)
    {
        auto team_id = GetTeamEntityId(guid);
        GetTeamEntityReturnError;
        RET_CHECK_RET(team.LeaveTeam(guid));
        if (team.empty())
        {
            EraseTeam(team.to_entityid());
        }
        return RET_OK;
    }

    uint32_t Teams::KickMember(Guid team_id, Guid current_leader, Guid  kick_guid)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(team.KickMember(current_leader, kick_guid));
        return RET_OK;
    }

    uint32_t Teams::DissMissTeam(Guid team_id, Guid current_leader)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(team.DissMiss(current_leader));
        EraseTeam(e);
        return RET_OK;
    }

    uint32_t Teams::DissMissTeamNoLeader(Guid team_id)
    {
        GetTeamPtrReturnError;
        return DissMissTeam(team_id, team.leader_id());
    }

    uint32_t Teams::AppointLeader(Guid team_id, Guid current_leader, Guid  new_leader)
    {
        GetTeamPtrReturnError;
        return team.AppointLeader(current_leader, new_leader);
    }

    uint32_t Teams::ApplyForTeam(Guid team_id, Guid guid)
    {
        GetTeamPtrReturnError;
        return team.ApplyForTeam(guid);
    }

    uint32_t Teams::RejectApplicant(Guid team_id, Guid guid)
    {
        GetTeamPtrReturnError;
        return team.RemoveApplicant(guid);
    }

    uint32_t Teams::AgreeApplicant(Guid team_id, Guid guid)
    {
        GetTeamPtrReturnError;
        return team.JoinTeam(guid);
    }

    void Teams::ClearApplyList(Guid team_id)
    {
        auto e = entt::to_entity(team_id);
        if (!reg().valid(e))
        {
            return;
        }
        auto& team = reg().get<Team>(e);
        team.ClearApplyList();
    }

    void Teams::EraseTeam(entt::entity team_id)
    {
        reg().destroy(team_id);
    }

}//namespace common

