#pragma once

#include "src/common_type/common_type.h"
#include "src/game_logic/comp/mission_comp.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/missions/missions_config_template.h"

#include "component_proto/mission_comp.pb.h"


class AcceptMissionP
{
public:
    AcceptMissionP(uint32_t mid) 
        : mission_id_(mid){}
public:
    uint32_t mission_id_{ 0 };
};
    
struct ConditionEvent
{
    uint32_t type_{ 0 };
    UInt32Vector condtion_ids_{};
    uint32_t ammount_{ 1 };
};

class MissionsBase : public EntityPtr
{
public:
    using event_mission_classify_type = std::unordered_map<uint32_t, UInt32Set>;
    MissionsBase();
	MissionsBase(IMissionConfig* config);

    const event_mission_classify_type& classify_for_unittest() const { return   event_missions_classify_; }
    const MissionsPbComp& missions() { return missions_; }
    std::size_t mission_size()const { return missions_.missions().size(); }
    std::size_t complete_size()const { return missions_.complete_missions_size(); }
    std::size_t type_set_size()const { return type_filter_.size(); }
    std::size_t can_reward_size();

    bool IsAccepted(uint32_t mission_id)const
    {
        auto& mission = missions_.missions();
        return mission.find(mission_id) != mission.end();
    }
    bool IsComplete(uint32_t mission_id)const
    {
        return missions_.complete_missions().find(mission_id) != missions_.complete_missions().end();
    }
    bool IsConditionCompleted(uint32_t condition_id, uint32_t progress_value);

    uint32_t GetReward(uint32_t mission_id);
    uint32_t Accept(const AcceptMissionP& param);
    uint32_t AcceptCheck(const AcceptMissionP& param);
    uint32_t Abandon(uint32_t mission_id);
    void CompleteAllMission();

    void receive(const ConditionEvent& c);
       
private:
    void DelMissionClassify(uint32_t mission_id);
       
    bool UpdateMissionByCompareCondition(const ConditionEvent& c, Mission& mission);
        
    void OnMissionComplete(const ConditionEvent& c, const TempCompleteList& temp_complete);
        
    IMissionConfig* mission_config_{ nullptr };
    MissionsPbComp missions_;
    event_mission_classify_type  event_missions_classify_;//key : classify mision by event type  , value :  misison list
    UInt32PairSet type_filter_;
};




