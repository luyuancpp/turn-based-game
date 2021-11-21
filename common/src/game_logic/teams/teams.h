#ifndef COMMON_SRC_GAME_LOGIC_TEAM_TEAMS_H_
#define COMMON_SRC_GAME_LOGIC_TEAM_TEAMS_H_

#include <unordered_map>

#include "src/common_type/common_type.h"
#include "src/game_logic/game_registry.h"
#include "entt/src/entt/entity/entity.hpp"
#include "src/snow_flake/snow_flake.h"
#include "src/game_logic/teams/team_event.h"

#include "team.h"

namespace common
{
class Teams : public Receiver<Teams>
{
public:
    static const std::size_t kMaxTeamSize = 10000;

    Teams();

    std::size_t team_size()const { return reg().size<Team>(); }
    std::size_t member_size(GameGuid team_id);
    std::size_t applicant_size_by_guid(GameGuid guid)const;
    std::size_t applicant_size_by_team_id(GameGuid team_id)const;
    std::size_t players_size()const { return reg().get<PlayerIdTeamIdMap>(my_entity_id_).size(); }
    GameGuid GetTeamId(GameGuid guid)const;
    entt::entity GetTeamEntityId(GameGuid guid)const;
    GameGuid last_team_id() const { return last_team_id_; }
    GameGuid leader_id_by_teamid(GameGuid team_id)const;
    GameGuid leader_id_by_guid(GameGuid guid)const;
    GameGuid first_applicant_id(GameGuid team_id)const;
       
    bool IsTeamsMax() const{ return team_size() >= kMaxTeamSize; }
    bool IsTeamFull(GameGuid team_id);
    bool PlayerInTheTeam(GameGuid team_id, GameGuid guid);
    bool PlayerInTeam(GameGuid guid)const;
    bool HasApplicant(GameGuid team_id, GameGuid guid)const;

    bool TestApplicantValueEqual(GameGuid team_id)const;
        
    uint32_t CreateTeam(const CreateTeamParam& param);
    uint32_t JoinTeam(GameGuid team_id, GameGuid guid);
    uint32_t JoinTeam(const UI64USet& member_list, GameGuid  team_id);
    uint32_t LeaveTeam(GameGuid guid);
    uint32_t KickMember(GameGuid team_id, GameGuid current_leader_id, GameGuid  kick_guid);
    uint32_t DissMissTeam(GameGuid team_id, GameGuid current_leader_id);
    uint32_t DissMissTeamNoLeader(GameGuid team_id);
    uint32_t AppointLeader(GameGuid team_id, GameGuid current_leader_id, GameGuid  nNewLeaderPlayerId);
    uint32_t ApplyForTeam(GameGuid team_id, GameGuid guid);
    uint32_t RemoveApplicant(GameGuid team_id, GameGuid apply_guid);
    uint32_t AgreeApplicant(GameGuid team_id, GameGuid apply_guid);
    void ClearApplyList(GameGuid team_id);
        
private:
    uint32_t CheckMemberInTeam(const UI64USet& member_list);
    void EraseTeam(entt::entity team_id);

    GameGuid last_team_id_{ 0 };
    EventManagerPtr emp_;
    entt::entity my_entity_id_{};
};
}//namespace common
#endif // COMMON_SRC_GAME_LOGIC_TEAM_TEAMS_H_

