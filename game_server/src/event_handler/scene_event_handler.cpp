#include "scene_event_handler.h"
#include "event_proto/scene_event.pb.h"
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void SceneEventHandler::Register(entt::dispatcher& dispatcher)
{
		dispatcher.sink<BeforeEnterScene>().connect<&SceneEventHandler::BeforeEnterSceneHandler>();
		dispatcher.sink<OnEnterScene>().connect<&SceneEventHandler::OnEnterSceneHandler>();
		dispatcher.sink<BeforeLeaveScene>().connect<&SceneEventHandler::BeforeLeaveSceneHandler>();
		dispatcher.sink<OnLeaveScene>().connect<&SceneEventHandler::OnLeaveSceneHandler>();
		dispatcher.sink<S2CEnterScene>().connect<&SceneEventHandler::S2CEnterSceneHandler>();
}

void SceneEventHandler::UnRegister(entt::dispatcher& dispatcher)
{
		dispatcher.sink<BeforeEnterScene>().disconnect<&SceneEventHandler::BeforeEnterSceneHandler>();
		dispatcher.sink<OnEnterScene>().disconnect<&SceneEventHandler::OnEnterSceneHandler>();
		dispatcher.sink<BeforeLeaveScene>().disconnect<&SceneEventHandler::BeforeLeaveSceneHandler>();
		dispatcher.sink<OnLeaveScene>().disconnect<&SceneEventHandler::OnLeaveSceneHandler>();
		dispatcher.sink<S2CEnterScene>().disconnect<&SceneEventHandler::S2CEnterSceneHandler>();
}

void SceneEventHandler::BeforeEnterSceneHandler(const BeforeEnterScene& message)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void SceneEventHandler::OnEnterSceneHandler(const OnEnterScene& message)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void SceneEventHandler::BeforeLeaveSceneHandler(const BeforeLeaveScene& message)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void SceneEventHandler::OnLeaveSceneHandler(const OnLeaveScene& message)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void SceneEventHandler::S2CEnterSceneHandler(const S2CEnterScene& message)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
