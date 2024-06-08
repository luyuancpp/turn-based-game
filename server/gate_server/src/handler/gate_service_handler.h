#pragma once
#include "common_proto/gate_service.pb.h"
class GateServiceHandler : public ::GateService
{
public:
	void StartGS(::google::protobuf::RpcController* controller,
		const ::GateNodeStartGSRequest* request,
		::Empty* response,
		 ::google::protobuf::Closure* done)override;

	void StopGS(::google::protobuf::RpcController* controller,
		const ::GateNodeStopGSRequest* request,
		::Empty* response,
		 ::google::protobuf::Closure* done)override;

	void PlayerEnterGs(::google::protobuf::RpcController* controller,
		const ::GateNodePlayerUpdateGameNodeRequest* request,
		::GateNodePlayerUpdateGameNodeResponese* response,
		 ::google::protobuf::Closure* done)override;

	void PlayerMessage(::google::protobuf::RpcController* controller,
		const ::NodeRouteMessageRequest* request,
		::Empty* response,
		 ::google::protobuf::Closure* done)override;

	void KickConnByCentre(::google::protobuf::RpcController* controller,
		const ::GateNodeKickConnRequest* request,
		::Empty* response,
		 ::google::protobuf::Closure* done)override;

	void RouteNodeStringMsg(::google::protobuf::RpcController* controller,
		const ::RouteMsgStringRequest* request,
		::RouteMsgStringResponse* response,
		 ::google::protobuf::Closure* done)override;

	void RoutePlayerStringMsg(::google::protobuf::RpcController* controller,
		const ::RoutePlayerMsgStringRequest* request,
		::RoutePlayerMsgStringResponse* response,
		 ::google::protobuf::Closure* done)override;

};

