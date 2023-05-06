#pragma once
#include "server_player_proto/scene_server_player.pb.h"
#include "player_service_replied.h"
class ServerPlayerSceneServiceRepliedHandler : public ::PlayerServiceReplied
{
public:
	PlayerServiceReplied::PlayerServiceReplied;
	void EnterSceneGs2Controller(entt::entity player,
		const ::Gs2ControllerEnterSceneRequest* request,
		::google::protobuf::Empty* response);

	void EnterSceneController2Gs(entt::entity player,
		const ::Controller2GsEnterSceneRequest* request,
		::google::protobuf::Empty* response);

	void LeaveSceneGs2Controller(entt::entity player,
		const ::Gs2ControllerLeaveSceneRequest* request,
		::google::protobuf::Empty* response);

	void LeaveSceneController2Gs(entt::entity player,
		const ::Controller2GsLeaveSceneRequest* request,
		::google::protobuf::Empty* response);

	void Gs2ControllerLeaveSceneAsyncSavePlayerComplete(entt::entity player,
		const ::Gs2ControllerLeaveSceneAsyncSavePlayerCompleteRequest* request,
		::google::protobuf::Empty* response);

	void Controller2GsEnterSceneS2C(entt::entity player,
		const ::EnterSceneS2CRequest* request,
		::EnterScenerS2CResponse* response);

 void CallMethod(const ::google::protobuf::MethodDescriptor* method,
   entt::entity player,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response)override 
  {
        switch(method->index()) {
		case 0:
			EnterSceneGs2Controller(player,
			nullptr,
			::google::protobuf::internal::DownCast<google::protobuf::Empty*>(response));
		break;
		case 1:
			EnterSceneController2Gs(player,
			nullptr,
			::google::protobuf::internal::DownCast<google::protobuf::Empty*>(response));
		break;
		case 2:
			LeaveSceneGs2Controller(player,
			nullptr,
			::google::protobuf::internal::DownCast<google::protobuf::Empty*>(response));
		break;
		case 3:
			LeaveSceneController2Gs(player,
			nullptr,
			::google::protobuf::internal::DownCast<google::protobuf::Empty*>(response));
		break;
		case 4:
			Gs2ControllerLeaveSceneAsyncSavePlayerComplete(player,
			nullptr,
			::google::protobuf::internal::DownCast<google::protobuf::Empty*>(response));
		break;
		case 5:
			Controller2GsEnterSceneS2C(player,
			nullptr,
			::google::protobuf::internal::DownCast<EnterScenerS2CResponse*>(response));
		break;
		default:
			GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
		break;
		}
	}

};