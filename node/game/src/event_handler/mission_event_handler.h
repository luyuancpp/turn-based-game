#pragma once

class AcceptMissionEvent;
class MissionConditionEvent;
class OnAcceptedMissionEvent;
class OnMissionAwardEvent;

class MissionEventHandler
{
public:
	static void Register();
	static void UnRegister();

	static void AcceptMissionEventHandler(const AcceptMissionEvent& message);
	static void MissionConditionEventHandler(const MissionConditionEvent& message);
	static void OnAcceptedMissionEventHandler(const OnAcceptedMissionEvent& message);
	static void OnMissionAwardEventHandler(const OnMissionAwardEvent& message);
};
