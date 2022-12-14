#pragma once
#include "player_service.h"
#include "logic_proto/common_server_player.pb.h"
class ServerPlayerLoginServiceImpl : public PlayerService {
public:
    using PlayerService::PlayerService;
public:
    void UpdateSessionController2Gs(entt::entity player,
        const ::UpdateSessionController2GsRequest* request,
        ::google::protobuf::Empty* response);
    void Controller2GsLogin(entt::entity player,
        const ::Controller2GsLoginRequest* request,
        ::google::protobuf::Empty* response);
    void Controller2GsEnterGateSucceed(entt::entity player,
        const ::Controller2GsEnterGateSucceedRequest* request,
        ::google::protobuf::Empty* response);
    void CallMethod(const ::google::protobuf::MethodDescriptor* method,
    entt::entity player,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response)override
    {
        switch(method->index()) {
        case 0:
            UpdateSessionController2Gs(player,
            ::google::protobuf::internal::DownCast<const ::UpdateSessionController2GsRequest*>( request),
            ::google::protobuf::internal::DownCast<::google::protobuf::Empty*>(response));
        break;
        case 1:
            Controller2GsLogin(player,
            ::google::protobuf::internal::DownCast<const ::Controller2GsLoginRequest*>( request),
            ::google::protobuf::internal::DownCast<::google::protobuf::Empty*>(response));
        break;
        case 2:
            Controller2GsEnterGateSucceed(player,
            ::google::protobuf::internal::DownCast<const ::Controller2GsEnterGateSucceedRequest*>( request),
            ::google::protobuf::internal::DownCast<::google::protobuf::Empty*>(response));
        break;
        default:
            GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
        break;
        }
    }
};