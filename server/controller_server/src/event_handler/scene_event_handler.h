#pragma once
#include "src/thread_local/thread_local_storage.h"

class BeforeEnterScene;
class OnEnterScene;
class BeforeLeaveScene;
class OnLeaveScene;
class S2CEnterScene;

class SceneEventHandler
{
public:
	static void Register();
	static void UnRegister();

	static void BeforeEnterSceneHandler(const BeforeEnterScene& message);
	static void OnEnterSceneHandler(const OnEnterScene& message);
	static void BeforeLeaveSceneHandler(const BeforeLeaveScene& message);
	static void OnLeaveSceneHandler(const OnLeaveScene& message);
	static void S2CEnterSceneHandler(const S2CEnterScene& message);
};
