#pragma once
#include "event_receiver.h"
#include "mission_event_receiver.h"
#include "scene_event_receiver.h"

void EventReceiver::Register(entt::dispatcher& dispatcher)
{
    MissionEventReceiver::Register(dispatcher);
    SceneEventReceiver::Register(dispatcher);
}

void EventReceiver::UnRegister(entt::dispatcher& dispatcher)
{
    MissionEventReceiver::UnRegister(dispatcher);
    SceneEventReceiver::UnRegister(dispatcher);
}
