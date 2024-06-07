#pragma once

#include "src/type_define/type_define.h"
#include "src/thread_local/thread_local_storage.h"
#include "src/util/snow_flake.h"

#include "team.h"

static constexpr std::size_t kMaxTeamSize = 10000;

class TeamSystem final
{
public:
    ~TeamSystem();

    static std::size_t team_size();
    static std::size_t member_size(Guid team_id);
    static std::size_t applicant_size_by_player_id(Guid guid);
    static std::size_t applicant_size_by_team_id(Guid team_id);
    static std::size_t players_size();
    static Guid GetTeamId(Guid guid);
    [[nodiscard]] Guid last_team_id() const;
    static Guid get_leader_id_by_team_id(Guid team_id);
    static Guid get_leader_id_by_player_id(Guid guid);
    static Guid first_applicant(Guid team_id);

    [[nodiscard]] static bool IsTeamListMax();
    static bool IsTeamFull(Guid team_id);
    static bool HasMember(Guid team_id, Guid guid);
    static bool HasTeam(Guid guid);
    static bool IsApplicant(Guid team_id, Guid guid);

    uint32_t CreateTeam(const CreateTeamP& param);
    static uint32_t JoinTeam(Guid team_id, Guid guid);
    static uint32_t JoinTeam(const UInt64Set& member_list, Guid team_id);
    static uint32_t LeaveTeam(Guid guid);
    static uint32_t KickMember(Guid team_id, Guid current_leader_id, Guid be_kick_id);
    static uint32_t Disbanded(Guid team_id, Guid current_leader_id);
    static uint32_t DisbandedTeamNoLeader(Guid team_id);
    static uint32_t AppointLeader(Guid team_id, Guid current_leader_id, Guid new_leader_id);
    static uint32_t ApplyToTeam(Guid team_id, Guid guid);
    static uint32_t DelApplicant(Guid team_id, Guid apply_guid);
    static void ClearApplyList(Guid team_id);

private:
    [[nodiscard]] static uint32_t CheckMemberInTeam(const UInt64Set& member_list);
    static void EraseTeam(entt::entity team_id);

    Guid last_team_id_{0}; //for test
};
