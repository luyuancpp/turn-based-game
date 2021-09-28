﻿#include <gtest/gtest.h>

#include "src/game_config/condition_config.h"
#include "src/game_config/mission_config.h"
#include "src/game_logic/comp/mission.hpp"
#include "src/game_logic/factories/mission_factories.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/op_code.h"
#include "src/game_logic/sys/mission_sys.hpp"
#include "src/game_logic/missions/missions.h"
#include "src/random/random.h"
#include "src/return_code/error_code.h"

#include "comp.pb.h"

using namespace common;

TEST(Missions, MakeMission)
{
    uint32_t mid = 1;
    Missions<mission_config, mission_row> ms;
    reg().remove<CheckSubType>(ms.entity());
    MakeMissionParam param{ ms.entity(),
        mid,
        mission_config::GetSingleton().key_id(mid)->condition_id(), 
        E_OP_CODE_TEST };
    
    auto& data = mission_config::GetSingleton().all();

    std::size_t s = 0;
    for (int32_t i = 0; i < data.data_size(); ++i)
    {
        auto id = data.data(i).id();
        param.mission_id_ = id;
        param.condition_id_ = &mission_config::GetSingleton().key_id(id)->condition_id();
        auto m = ms.MakeMission(param);
        ++s;
    }

    EXPECT_EQ(s, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());
    ms.CompleteAllMission();
    EXPECT_EQ(0, ms.mission_size());
    EXPECT_EQ(s, ms.completemission_size());
}

TEST(Missions, RadomCondtion)
{
    uint32_t mid = 3;
    Missions<mission_config, mission_row> ms;
    MakePlayerMissionParam param{ms.entity(), mid,  E_OP_CODE_TEST };    
    auto cids = mission_config::GetSingleton().key_id(mid);    
    RandomMision(param, ms);
    auto& missions = ms.missions();
    auto it =  std::find(cids->random_condition_pool().begin(), cids->random_condition_pool().end(),
        missions.missions().find(mid)->second.conditions(0).id());
    EXPECT_TRUE(it != cids->random_condition_pool().end());
    EXPECT_EQ(1, missions.missions().find(mid)->second.conditions_size());
}

TEST(Missions, RepeatedMission)
{
    Missions<mission_config, mission_row> ms;
    {
        uint32_t mid = 1;
        MakeMissionParam param{ ms.entity(),
        mid,
        mission_config::GetSingleton().key_id(mid)->condition_id(), E_OP_CODE_TEST };
        EXPECT_EQ(RET_OK, ms.MakeMission(param));
        EXPECT_EQ(RET_MISSION_ID_REPTEATED, ms.MakeMission(param));
    }

    {
        MakePlayerMissionParam param{ ms.entity(), 3,  E_OP_CODE_TEST };
        MakePlayerMissionParam param2{ ms.entity(), 2,  E_OP_CODE_TEST };
        EXPECT_EQ(RET_OK, RandomMision(param, ms));
        EXPECT_EQ(RET_MISSION_TYPE_REPTEATED, RandomMision(param2, ms));
    }
}

TEST(Missions, TriggerCondition)
{
    Missions<mission_config, mission_row> ms;
    uint32_t mid = 1;
    //auto mrow = mission_config::GetSingleton().key_id(mid);
    MakePlayerMissionParam param{ ms.entity(),   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, RandomMision(param, ms));
    EXPECT_EQ(1, ms.type_set_size());
    ConditionEvent ce{ ms.entity(), E_CONDITION_KILL_MONSTER, {1}, 1 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condtion_ids_ = { 2 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condtion_ids_ = { 3 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condtion_ids_ = { 4 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(0, ms.mission_size());
    EXPECT_EQ(1, ms.completemission_size());
    EXPECT_EQ(0, ms.type_set_size());
}

TEST(Missions, TypeSize)
{
    Missions<mission_config, mission_row> ms;
    uint32_t mid = 6;
    //auto mrow = mission_config::GetSingleton().key_id(mid);
    MakePlayerMissionParam param{ ms.entity(),   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, RandomMision(param, ms));
    EXPECT_TRUE(ms.IsAcceptedMission(mid));
    EXPECT_FALSE(ms.IsCompleteMission(mid));
    for (uint32_t i = E_CONDITION_KILL_MONSTER; i < E_CONDITION_COMSTUM; ++i)
    {
        EXPECT_EQ(1, ms.type_mission_id().find(i)->second.size());
    }    
    ConditionEvent ce{ ms.entity(), E_CONDITION_KILL_MONSTER, {1}, 1 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condition_type_ = E_CONDITION_TALK_WITH_NPC;
    ce.condtion_ids_ = { 1 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condition_type_ = E_CONDITION_COMPLELETE_CONDITION;
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condition_type_ = E_CONDITION_USE_ITEM;
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condition_type_ = E_CONDITION_LEVEUP;
    ce.condtion_ids_ = { 10 };
    ms.TriggerConditionEvent(ce);
    EXPECT_EQ(1, ms.mission_size());
    EXPECT_EQ(0, ms.completemission_size());

    ce.condition_type_ = E_CONDITION_INTERATION;
    ce.condtion_ids_ = { 1};
    ms.TriggerConditionEvent(ce);
    
    EXPECT_EQ(0, ms.mission_size());
    EXPECT_EQ(1, ms.completemission_size());
    EXPECT_FALSE(ms.IsAcceptedMission(mid));
    EXPECT_TRUE(ms.IsCompleteMission(mid));
    EXPECT_EQ(0, ms.type_set_size());
    for (uint32_t i = E_CONDITION_KILL_MONSTER; i < E_CONDITION_COMSTUM; ++i)
    {
        EXPECT_EQ(0, ms.type_mission_id().find(i)->second.size());
    }
}

TEST(Missions, CompleteRemakeMission)
{
    auto mm = MakePlayerMissionMap();
    uint32_t mid = 4;
    //auto mrow = mission_config::GetSingleton().key_id(mid);
    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    EXPECT_EQ(1, reg().get<UI32PairSet>(mm).size());
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));    
    EXPECT_EQ(RET_MISSION_COMPLETE, MakePlayerMission(param));
    reg().clear();
}


TEST(Missions, OnCompleteMission)
{
    auto mm = MakePlayerMissionMap();
    uint32_t mid = 7;

    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    EXPECT_EQ(1, reg().get<UI32PairSet>(mm).size());
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));

    auto next_mission = ++mid;
    EXPECT_TRUE(IsAcceptedMission({ mm,  next_mission }));
    EXPECT_FALSE(IsCompleteMission({ mm, next_mission }));
    for (uint32_t i = E_CONDITION_KILL_MONSTER; i < E_CONDITION_INTERATION; ++i)
    {
        ce.condtion_ids_ = { i };
        TriggerConditionEvent(ce);
        EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
        EXPECT_TRUE(IsCompleteMission({ mm, mid }));

        auto next_mission = ++mid;
        EXPECT_TRUE(IsAcceptedMission({ mm,  next_mission }));
        EXPECT_FALSE(IsCompleteMission({ mm, next_mission }));
    }

    reg().clear();
}

TEST(Missions, AcceptNextMirroMission)
{
    auto mm = MakePlayerMissionMap();
    uint32_t mid = 7;
    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    auto& next_mission_set =  reg().emplace<NextTimeAcceptMission>(mm);
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    EXPECT_EQ(1, reg().get<UI32PairSet>(mm).size());
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));

    auto next_mission_id = ++mid;
    EXPECT_FALSE(IsAcceptedMission({ mm,  next_mission_id }));
    EXPECT_FALSE(IsCompleteMission({ mm, next_mission_id }));
    EXPECT_TRUE(next_mission_set.next_time_accept_mission_id_.find(next_mission_id)
        != next_mission_set.next_time_accept_mission_id_.end());
    reg().clear();
}

TEST(Missions, MissionCondition)
{
    auto mm = MakePlayerMissionMap();

    uint32_t mid = 14;
    uint32_t mid1 = 15;
    uint32_t mid2 = 16;
    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    param.mission_id_ = mid1;
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    param.mission_id_ = mid2;
    EXPECT_EQ(RET_OK, MakePlayerMission(param));

    EXPECT_TRUE(IsAcceptedMission({ mm, mid }));
    EXPECT_FALSE(IsCompleteMission({ mm, mid }));
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));
    EXPECT_FALSE(IsAcceptedMission({ mm, mid1 }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid1 }));
    EXPECT_FALSE(IsAcceptedMission({ mm, mid2 }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid2 }));
    reg().clear();
}

TEST(Missions, ConditionAmount)
{
    auto mm = MakePlayerMissionMap();

    uint32_t mid = 13;

    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));

    EXPECT_TRUE(IsAcceptedMission({ mm, mid }));
    EXPECT_FALSE(IsCompleteMission({ mm, mid }));
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_TRUE(IsAcceptedMission({ mm, mid }));
    EXPECT_FALSE(IsCompleteMission({ mm, mid }));
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));
    reg().clear();
}

TEST(Missions, MissionRewardList)
{
    auto mm = MakePlayerMissionMap();

    uint32_t mid = 12;

    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));
    EXPECT_EQ(RET_MISSION_GET_REWARD_NO_MISSION_ID, GetMissionReward({ mm, mid }));
    EXPECT_TRUE(IsAcceptedMission({ mm, mid }));
    EXPECT_FALSE(IsCompleteMission({ mm, mid }));
    ConditionEvent ce{ mm, E_CONDITION_KILL_MONSTER, {1}, 1 };
    TriggerConditionEvent(ce);
    EXPECT_FALSE(IsAcceptedMission({ mm, mid }));
    EXPECT_TRUE(IsCompleteMission({ mm, mid }));
    EXPECT_EQ(RET_OK, GetMissionReward({ mm, mid }));
    EXPECT_EQ(RET_MISSION_GET_REWARD_NO_MISSION_ID, GetMissionReward({ mm, mid }));
    EXPECT_EQ(0, reg().get<CompleteMissionsId>(mm).can_reward_mission_id().size());
    reg().clear();
}

TEST(Missions, RemoveMission)
{
    auto mm = MakePlayerMissionMap();

    uint32_t mid = 12;

    MakePlayerMissionParam param{ mm,   mid,  E_OP_CODE_TEST };
    EXPECT_EQ(RET_OK, MakePlayerMission(param));

    EXPECT_EQ(1, reg().get<MissionMap>(mm).missions().size());
    EXPECT_EQ(0, reg().get<CompleteMissionsId>(mm).can_reward_mission_id().size());
    EXPECT_EQ(1, reg().get<TypeSubTypeSet>(mm).size());
    auto& type_missions = reg().get<TypeMissionIdMap>(mm);

    EXPECT_EQ(1, type_missions[E_CONDITION_KILL_MONSTER].size());
    reg().get<CompleteMissionsId>(mm).mutable_can_reward_mission_id()->insert({ mid, true });
    MissionIdParam rp{ mm, mid,  E_OP_CODE_TEST };
    RemoveMission(rp);

    EXPECT_EQ(0, reg().get<MissionMap>(mm).missions().size());
    EXPECT_EQ(0, reg().get<CompleteMissionsId>(mm).can_reward_mission_id().size());
    EXPECT_EQ(0, reg().get<TypeSubTypeSet>(mm).size());
    EXPECT_EQ(0, type_missions[E_CONDITION_KILL_MONSTER].size());
    reg().clear();
}

TEST(Missions, MissionAutoReward)
{
}

TEST(Missions, MissionTimeOut)
{

}

int main(int argc, char** argv)
{
    Random::GetSingleton();
    condition_config::GetSingleton().load();
    mission_config::GetSingleton().load();
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

