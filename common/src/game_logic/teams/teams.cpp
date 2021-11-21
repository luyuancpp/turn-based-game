#include "teams.h"

#include "src/return_code/return_notice_code.h"

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
        reg().emplace<PlayerIdTeamIdMap>(my_entity_id_, PlayerIdTeamIdMap());
    }

    std::size_t Teams::member_size(GameGuid team_id)
    {
        GetTeamReturn(0);
        return team.member_size();
    }

    std::size_t Teams::applicant_size_by_guid(GameGuid guid) const
    {
        auto team_id = GetTeamId(guid);
        return applicant_size_by_team_id(team_id);
    }

    std::size_t Teams::applicant_size_by_team_id(GameGuid team_id) const
    {
        GetTeamReturn(0);
        return team.applicant_size();
    }

    GameGuid Teams::GetTeamId(GameGuid guid)const
    {
        auto& player_team_map_ = reg().get<PlayerIdTeamIdMap>(my_entity_id_);
        auto it = player_team_map_.find(guid);
        if (it == player_team_map_.end())
        {
            return kEmptyGameGuid;
        }
        return entt::to_integral(it->second);
    }

    entt::entity Teams::GetTeamEntityId(GameGuid guid) const
    {
        auto& player_team_map_ = reg().get<PlayerIdTeamIdMap>(my_entity_id_);
        auto it = player_team_map_.find(guid);
        if (it == player_team_map_.end())
        {
            return entt::null;
        }
        return it->second;
    }

    common::GameGuid Teams::leader_id_by_teamid(GameGuid team_id) const
    {
        GetTeamReturn(kEmptyGameGuid);
        return team.leader_id();
    }

    common::GameGuid Teams::leader_id_by_guid(GameGuid guid) const
    {
        auto team_id = GetTeamId(guid);
        return leader_id_by_teamid(team_id);
    }
    
    common::GameGuid Teams::first_applicant_id(GameGuid team_id) const
    {
        GetTeamReturn(0);
        return team.first_applicant_id();
    }
    bool Teams::IsTeamFull(GameGuid team_id)
    {
        GetTeamReturn(false);
        return team.IsFull();
    }

    bool Teams::PlayerInTheTeam(GameGuid team_id, GameGuid guid)
    {
        GetTeamReturn(false);
        return team.InMyTeam(guid);
    }

    bool Teams::PlayerInTeam(GameGuid guid) const
    {
        auto& player_team_map_ = reg().get<PlayerIdTeamIdMap>(my_entity_id_);
        return player_team_map_.find(guid) != player_team_map_.end(); 
    }

    bool Teams::HasApplicant(GameGuid team_id, GameGuid guid) const
    {
        GetTeamReturn(false);
        return team.HasApplicant(guid);
    }

    bool Teams::TestApplicantValueEqual(GameGuid team_id)const
    {
        GetTeamReturn(false);
        return team.TestApplicantValueEqual();
    }

    uint32_t Teams::CreateTeam(const CreateTeamParam& param)
    {
        if (IsTeamsMax())
        {
            return RET_TEAM_TEAM_LIST_MAX;
        }
        if (PlayerInTeam(param.leader_id_))
        {
            return RET_TEAM_MEMBER_IN_TEAM;
        }
        RET_CHECK_RET(CheckMemberInTeam(param.members));

        auto e = reg().create();
        TeamsParam ts_param{e, my_entity_id_, emp_, &reg() };
        auto team = reg().emplace<Team>(e, param, ts_param);

        PlayerInTeamF f_in_the_team;
        f_in_the_team.cb_ = std::bind(&Teams::PlayerInTeam, this, std::placeholders::_1);
        reg().emplace<PlayerInTeamF>(e, f_in_the_team);

        team.OnCreate();
        last_team_id_ = entt::to_integral(e);
        return RET_OK;
    }

    uint32_t Teams::JoinTeam(GameGuid team_id, GameGuid guid)
    {
        GetTeamPtrReturnError;
        return team.JoinTeam(guid);
    }

    uint32_t Teams::JoinTeam(const UI64USet& member_list, GameGuid  team_id)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(CheckMemberInTeam(member_list));
        for (auto& it : member_list)
        {
            RET_CHECK_RET(team.JoinTeam(it));
        }
        return RET_OK;
    }

    uint32_t Teams::CheckMemberInTeam(const UI64USet& member_list)
    {
        for (auto& it : member_list)
        {
            if (PlayerInTeam(it))
            {
                return RET_TEAM_MEMBER_IN_TEAM;
            }
        }
        return RET_OK;
    }

    uint32_t Teams::LeaveTeam(GameGuid guid)
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

    uint32_t Teams::KickMember(GameGuid team_id, GameGuid current_leader_id, GameGuid  kick_guid)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(team.KickMember(current_leader_id, kick_guid));
        return RET_OK;
    }

    uint32_t Teams::DissMissTeam(GameGuid team_id, GameGuid current_leader_id)
    {
        GetTeamPtrReturnError;
        RET_CHECK_RET(team.DissMiss(current_leader_id));
        EraseTeam(e);
        return RET_OK;
    }

    uint32_t Teams::DissMissTeamNoLeader(GameGuid team_id)
    {
        GetTeamPtrReturnError;
        return DissMissTeam(team_id, team.leader_id());
    }

    uint32_t Teams::AppointLeader(GameGuid team_id, GameGuid current_leader_id, GameGuid  new_leader_guid)
    {
        GetTeamPtrReturnError;
        return team.AppointLeader(current_leader_id, new_leader_guid);
    }

    uint32_t Teams::ApplyForTeam(GameGuid team_id, GameGuid guid)
    {
        GetTeamPtrReturnError;
        return team.ApplyForTeam(guid);
    }

    uint32_t Teams::RemoveApplicant(GameGuid team_id, GameGuid apply_guid)
    {
        GetTeamPtrReturnError;
        return team.RemoveApplicant(apply_guid);
    }

    uint32_t Teams::AgreeApplicant(GameGuid team_id, GameGuid applicant_id)
    {
        GetTeamPtrReturnError;
        return team.AgreeApplicant(applicant_id);
    }

    void Teams::ClearApplyList(GameGuid team_id)
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

