#include "missions_base.h"


#include "muduo/base/Logging.h"

#include "src/game_config/condition_config.h"
#include "src/game_logic/constants/mission_constants.h"
#include "src/game_logic/game_registry.h"

#include "src/util/random.h"
#include "src/game_logic/tips_id.h"


static std::vector<std::function<bool(int32_t, int32_t)>> f_c{
	{[](int32_t a, int32_t b) {return a >= b; }},
	{[](int32_t a, int32_t b) {return a > b; }},
	{[](int32_t a, int32_t b) {return a <= b; }},
	{[](int32_t a, int32_t b) {return a < b; }},
	{[](int32_t a, int32_t b) {return a == b; }},
};

MissionsComp::MissionsComp(entt::entity event_owner)
    : MissionsComp(event_owner, &MissionConfig::GetSingleton()){}

MissionsComp::MissionsComp(entt::entity event_owner, IMissionConfig* config)
    : EventOwner(event_owner),
      mission_config_(config)
{
    for (uint32_t i = E_CONDITION_KILL_MONSTER; i < E_CONDITION_MAX; ++i)
    {
         event_missions_classify_.emplace(i, UInt32Set{});
    }
    if (mission_config_->CheckTypeRepeated())
    {
        registry.emplace<CheckTypeRepeatd>(event_owner_);
    }
}

std::size_t MissionsComp::can_reward_size()
{
    auto try_mission_reward = registry.try_get<MissionRewardPbComp>(event_owner_);
    if (nullptr == try_mission_reward)
    {
        return 0;
    }
    return try_mission_reward->can_reward_mission_id_size();
}

bool MissionsComp::IsConditionCompleted(uint32_t condition_id, uint32_t progress_value)
{
	auto p = condition_config::GetSingleton().get(condition_id);
	if (nullptr == p)
	{
        return false;
	}
	std::size_t operator_id = std::size_t(p->operation());
	if (!(operator_id >= 0 && operator_id < f_c.size()))
	{
		operator_id = 0;
	}
    return f_c[operator_id](progress_value, p->amount());
}

uint32_t MissionsComp::GetReward(uint32_t missin_id)
{
	auto try_mission_reward = registry.try_get<MissionRewardPbComp>(event_owner_);
	if (nullptr == try_mission_reward)
	{
		return kRetMissionPlayerMissionCompNotFound;
	}
    auto rmid = try_mission_reward->mutable_can_reward_mission_id();
    auto it = try_mission_reward->mutable_can_reward_mission_id()->find(missin_id);
    if (it == rmid->end())
    {
        return kRetMissionGetRewardNoMissionId;
    }
    rmid->erase(missin_id);
    return kRetOK;
}

uint32_t MissionsComp::Accept(const AcceptMissionP& param)
{
    auto mission_id = param.mission_id_;
    if (missions_comp_pb_.missions().count(mission_id) > 0)//已经接受过
    {
        return kRetMissionIdRepeated;
    }
    if (missions_comp_pb_.complete_missions().count(mission_id) > 0)//已经完成
    {
        return kRetMissionComplete;
    }
    if (!mission_config_->HasKey(mission_id))
    {
        return kRetTableId;
    }
    auto mission_sub_type = mission_config_->mission_sub_type(mission_id);
    auto mission_type = mission_config_->mission_type(mission_id);
    bool check_type_repeated =  mission_sub_type > 0 && registry.any_of<CheckTypeRepeatd>(event_owner_);
    if (check_type_repeated)
    {
        UInt32PairSet::value_type p(mission_type, mission_sub_type);
        CheckCondtion(type_filter_.find(p) != type_filter_.end(), kRetMisionTypeRepeated);
    }
    MissionPbComp m;
    m.set_id(mission_id);
    const auto& conditionids = mission_config_->condition_id(mission_id);
    for (int32_t i = 0; i < conditionids.size(); ++i)
    {
        auto cid = conditionids[i];
        auto p = condition_config::GetSingleton().get(cid);
        if (nullptr == p)
        {
            LOG_ERROR << "has not condtion" << cid;
            continue;
        }
        m.add_progress(0);
        event_missions_classify_[p->condition_type()].emplace(mission_id);
    }
    missions_comp_pb_.mutable_missions()->insert({ mission_id, std::move(m) });
    if (check_type_repeated)
    {
        UInt32PairSet::value_type p(mission_type, mission_sub_type);
        type_filter_.emplace(p);
    }
    return kRetOK;
}

uint32_t MissionsComp::AcceptCheck(const AcceptMissionP& param)
{
    return kRetOK;
}

uint32_t MissionsComp::Abandon(uint32_t mission_id)
{
	auto try_mission_reward = registry.try_get<MissionRewardPbComp>(event_owner_);
	if (nullptr != try_mission_reward)
	{
        try_mission_reward->mutable_can_reward_mission_id()->erase(mission_id);
	}
    missions_comp_pb_.mutable_missions()->erase(mission_id);
    missions_comp_pb_.mutable_complete_missions()->erase(mission_id);
    missions_comp_pb_.mutable_mission_begin_time()->erase(mission_id);
    DelMissionClassify(mission_id);
    return kRetOK;
}

void MissionsComp::CompleteAllMission()
{
    for (auto& meit : missions_comp_pb_.missions())
    {
        missions_comp_pb_.mutable_complete_missions()->insert({ meit.first, false });
    }
    missions_comp_pb_.mutable_missions()->clear();
}

void MissionsComp::Receive(const ConditionEvent& c)
{
    if (c.condtion_ids_.empty())
    {
        return;
    }
    auto it =  event_missions_classify_.find(c.type_);
    if (it ==  event_missions_classify_.end())
    {
        return;
    }
    auto missions = missions_comp_pb_.mutable_missions();
    UInt32Set temp_complete;
    auto& classify_missions = it->second;//根据事件触发类型分类的任务
    for (auto lit : classify_missions)
    {
        auto mit = missions->find(lit);
        if (mit == missions->end())
        {
            continue;
        }
        auto& mission = mit->second;
        if (!UpdateMissionByCompareCondition(c, mission))
        {
            continue;
        }
        const auto& conditions = mission_config_->condition_id(mission.id());
        bool is_all_condition_complete = true;
        for (int32_t i = 0; i < mission.progress_size() && i < conditions.size(); ++i)
        {
            if (IsConditionCompleted(conditions[i], mission.progress(i)))
            {
                continue;
            }
            is_all_condition_complete = false;
            break;
        }
        if (!is_all_condition_complete)
        {
            break;
        }
        mission.set_status(MissionPbComp::E_MISSION_COMPLETE);
        // to client
        temp_complete.emplace(mission.id());
        missions->erase(mit);
    }

    OnMissionComplete(c, temp_complete);
}

void MissionsComp::DelMissionClassify(uint32_t mission_id)
{
    auto& config_conditions = mission_config_->condition_id(mission_id);
    for (int32_t i = 0; i < config_conditions.size(); ++i)
    {
        auto condition_row = condition_config::GetSingleton().get(config_conditions.Get(i));
        if (nullptr == condition_row)
        {
            continue;
        }
        event_missions_classify_[condition_row->condition_type()].erase(mission_id);
    }
    auto mission_sub_type = mission_config_->mission_sub_type(mission_id);
    bool check_type_repeated = mission_sub_type > 0 && registry.any_of<CheckTypeRepeatd>(event_owner_);
    if (check_type_repeated)
    {
		UInt32PairSet::value_type p(mission_config_->mission_type(mission_id), mission_sub_type);
		type_filter_.erase(p);
    }
}

bool MissionsComp::UpdateMissionByCompareCondition(const ConditionEvent& ev, MissionPbComp& mission)
{
    if (ev.condtion_ids_.empty())
    {
        return false;
    }
    bool mission_updated = false;
    //如果我删除了某个条件，老玩家数据会不会错?正常任务是不能删除的，但是可以考虑删除条件
    auto& mission_conditions = mission_config_->condition_id(mission.id());
    for (int32_t i = 0; i < mission.progress_size() && i < mission_conditions.size(); ++i)
    {
        auto condition_row = condition_config::GetSingleton().get(mission_conditions.at(i));
        if (nullptr == condition_row)
        {
            continue;
        }
        auto old_progress = mission.progress(i);
		if (IsConditionCompleted(condition_row->id(), old_progress))
		{
			continue;
		}
        if (ev.type_ != condition_row->condition_type())
        {
            continue;
        }
        //表检测至少有一个condition
        std::size_t config_condition_size = 0;
        std::size_t equal_condition_size = 0;
        auto calc_equal_condition_size = [&equal_condition_size, &ev, &config_condition_size](auto index, const auto& config_conditions)
        {
			if (config_conditions.size() > 0)
			{
				++config_condition_size;
			}
            if (ev.condtion_ids_.size() <= index)
            {
                return;
            }           
			for (int32_t ci = 0; ci < config_conditions.size(); ++ci)
			{
				if (ev.condtion_ids_[index] != config_conditions.Get(ci))
				{
					continue;
				}
				++equal_condition_size;
				break;
			}
        };
        calc_equal_condition_size(0, condition_row->condition1());
        calc_equal_condition_size(1, condition_row->condition2());
        calc_equal_condition_size(2, condition_row->condition3());
        calc_equal_condition_size(3, condition_row->condition4());
        if (config_condition_size == 0 || equal_condition_size != config_condition_size)
        {
            continue;
        }
        mission_updated = true;
        mission.set_progress(i , ev.ammount_ + old_progress);
        auto new_progress = mission.progress(i);
        if (!IsConditionCompleted(condition_row->id(), new_progress))
        {
            continue;
        }
        // to client
        mission.set_progress(i, std::min(new_progress, condition_row->amount()));
        // to client
    }
    return mission_updated;
}

void MissionsComp::OnMissionComplete(const ConditionEvent& c, const UInt32Set& temp_complete)
{
    if (temp_complete.empty())
    {
        return;
    }
    auto try_mission_reward = registry.try_get<MissionRewardPbComp>(event_owner_);
    for (auto& mission_id : temp_complete)
    {
        missions_comp_pb_.mutable_complete_missions()->insert({ mission_id, true });
        if (nullptr != try_mission_reward && mission_config_->reward_id(mission_id) > 0)
        {
            try_mission_reward->mutable_can_reward_mission_id()->insert({ mission_id, false });
        }
        DelMissionClassify(mission_id);

        //如果是活动不用走
        // todo event 
        auto& next_missions = mission_config_->next_mission_id(mission_id);
        auto next_time_accpet = registry.try_get<NextTimeAcceptMission>(event_owner_);
        if (nullptr == next_time_accpet)
        {
            for (int32_t i = 0; i < next_missions.size(); ++i)
            {
                auto next_mission = next_missions.Get(i);
                AcceptMissionP param{ next_mission};
                Accept(param);
            }
        }
        else
        {
            for (int32_t i = 0; i < next_missions.size(); ++i)
            {
                next_time_accpet->next_time_accept_mission_id_.emplace(next_missions.Get(i));
            }
        }
    }
    
    ConditionEvent ce{ E_CONDITION_COMPLELTE_MISSION, {}, 1 };
    for (auto& it : temp_complete)
    {
        ce.condtion_ids_ = { it };
        Receive(ce);
    }
}
