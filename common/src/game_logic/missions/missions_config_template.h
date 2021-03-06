#pragma once

#include "src/game_config/mission_config.h"


struct IMissionConfig 
{
    virtual uint32_t mission_type(uint32_t id){ return 0; }
    virtual uint32_t mission_sub_type(uint32_t id) { return 0; }
    virtual uint32_t reward_id(uint32_t id) { return 0; }
    virtual bool auto_reward(uint32_t mission_id) { return 0; }
    virtual const ::google::protobuf::RepeatedField<uint32_t>& condition_id(uint32_t mission_id)
    {
        thread_local ::google::protobuf::RepeatedField<uint32_t> s;
            s.Clear();
            return s;
    }
    virtual const ::google::protobuf::RepeatedField<uint32_t>& next_mission_id(uint32_t mission_id)
    {
        thread_local ::google::protobuf::RepeatedField<uint32_t> s;
        s.Clear();
        return s;
    }
    virtual bool HasMainSubTypeCheck() { return false; }
    virtual bool HasKey(uint32_t id) { return false; }
};

struct MissionConfig : public IMissionConfig
{
    static MissionConfig& GetSingleton() { thread_local MissionConfig singleton; return singleton; }

    virtual uint32_t mission_type(uint32_t id)override
    {
        auto mrow = mission_config::GetSingleton().get(id);
        if (nullptr == mrow)
        {
            return 0;
        }
        return mrow->mission_type();
    }

    virtual uint32_t mission_sub_type(uint32_t id)override
    {
        auto mrow = mission_config::GetSingleton().get(id);
        if (nullptr == mrow)
        {
            return 0;
        }
        return mrow->mission_sub_type();
    }

    virtual uint32_t reward_id(uint32_t id)override
    {
        auto mrow = mission_config::GetSingleton().get(id);
        if (nullptr == mrow)
        {
            return 0;
        }
        return mrow->reward_id();
    }

    virtual bool auto_reward(uint32_t mission_id)override
    {
        auto p = mission_config::GetSingleton().get(mission_id);
        if (nullptr == p)
        {
            return false;
        }
        return nullptr != p && p->auto_reward() > 0;
    }

    virtual const ::google::protobuf::RepeatedField<uint32_t>& condition_id(uint32_t mission_id) override
    {
        auto p = mission_config::GetSingleton().get(mission_id);
        if (nullptr == p)
        {
            static ::google::protobuf::RepeatedField<uint32_t> s;
            s.Clear();
            return s;
        }
        return p->condition_id();
    }

    virtual const ::google::protobuf::RepeatedField<uint32_t>& next_mission_id(uint32_t mission_id)override
    {
        auto p = mission_config::GetSingleton().get(mission_id);
        if (nullptr == p)
        {
            static ::google::protobuf::RepeatedField<uint32_t> s;
            s.Clear();
            return s;
        }
        return p->next_mission_id();
    }

    virtual bool HasMainSubTypeCheck() override { return true;   }
    virtual bool HasKey(uint32_t id)override { return nullptr !=  mission_config::GetSingleton().get(id); }
};
