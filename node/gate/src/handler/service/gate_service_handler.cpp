#include "gate_service_handler.h"
#include "thread_local/storage.h"
#include "system/network/message_system.h"
///<<< BEGIN WRITING YOUR CODE
#include "muduo/base/Logging.h"

#include "gate_node.h"
#include "network/gate_session.h"
#include "network/rpc_msg_route.h"
#include "thread_local/storage_gate.h"
#include "util/pb.h"

#include "proto/logic/component/player_network_comp.pb.h"
///<<< END WRITING YOUR CODE

void GateServiceHandler::RegisterGame(::google::protobuf::RpcController* controller,
	const ::RegisterGameRequest* request,
	::Empty* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	// Centre server notification
	entt::entity requestGameNodeId{ request->game_node_id() };
	if (tls.gameNodeRegistry.valid(requestGameNodeId))
	{
		LOG_ERROR << "Game node reconnect";
		return;
	}
	Destroy(tls.gameNodeRegistry, requestGameNodeId);
	auto gameNodeId = tls.gameNodeRegistry.create(requestGameNodeId);
	if (gameNodeId != requestGameNodeId)
	{
		LOG_ERROR << "Create game node failed";
		return;
	}

	InetAddress gameServiceAddr(request->rpc_server().ip(), request->rpc_server().port());
	auto& gameNode = tls.gameNodeRegistry.emplace<RpcClientPtr>(gameNodeId,
		std::make_unique<RpcClientPtr::element_type>(
			EventLoop::getEventLoopOfCurrentThread(),
			gameServiceAddr));
	gameNode->registerService(&g_gate_node->GetServiceHandler());
	gameNode->connect();

	LOG_INFO << "On game register: " << MessageToJsonString(request);
	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::UnRegisterGame(::google::protobuf::RpcController* controller,
	const ::UnRegisterGameRequest* request,
	::Empty* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	entt::entity requestGameNodeId{ request->game_node_id() };
	Destroy(tls.gameNodeRegistry, requestGameNodeId);
	LOG_INFO << "On game unregister: " << MessageToJsonString(request);
	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::PlayerEnterGs(::google::protobuf::RpcController* controller,
	const ::RegisterSessionGameNodeRequest* request,
	::RegisterSessionGameNodeResponse* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	auto sessionIt = tls_gate.sessions().find(request->session_info().session_id());
	if (sessionIt == tls_gate.sessions().end())
	{
		LOG_ERROR << "Session ID not found for PlayerEnterGs, session ID: " << request->session_info().session_id();
		return;
	}
	// Handle potential asynchronous issue if the GS sends while Gate is updating GS
	sessionIt->second.game_node_id_ = request->game_node_id();
	response->mutable_session_info()->set_session_id(request->session_info().session_id());
	LOG_INFO << "Player entered GS, session ID: " << request->session_info().session_id()
		<< ", game node ID: " << request->game_node_id();
	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::PlayerMessage(::google::protobuf::RpcController* controller,
	const ::NodeRouteMessageRequest* request,
	::Empty* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	auto sessionIt = tls_gate.sessions().find(request->head().session_id());
	if (sessionIt == tls_gate.sessions().end())
	{
		LOG_ERROR << "Connection ID not found for PlayerMessage, session ID: " << request->head().session_id();
		return;
	}
	g_gate_node->Send(sessionIt->second.conn_, request->body());
	//LOG_TRACE << "Player message routed, session ID: " << request->head().session_id();
	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::KickConnByCentre(::google::protobuf::RpcController* controller,
	const ::GateNodeKickConnRequest* request,
	::Empty* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	Destroy(tls.sceneRegistry, entt::entity{ request->session_id() });
	LOG_INFO << "Session ID kicked by Centre: " << request->session_id();
	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::RouteNodeStringMsg(::google::protobuf::RpcController* controller,
	const ::RouteMsgStringRequest* request,
	::RouteMsgStringResponse* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE

	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::RoutePlayerStringMsg(::google::protobuf::RpcController* controller,
	const ::RoutePlayerMsgStringRequest* request,
	::RoutePlayerMsgStringResponse* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE

	///<<< END WRITING YOUR CODE
}

void GateServiceHandler::BroadCast2PlayerMessage(::google::protobuf::RpcController* controller,
	const ::BroadCast2PlayerRequest* request,
	::Empty* response,
	::google::protobuf::Closure* done)
{
	///<<< BEGIN WRITING YOUR CODE
	for (auto&& sessionId : request->session_list())
	{
		auto sessionIt = tls_gate.sessions().find(sessionId);
		if (sessionIt == tls_gate.sessions().end())
		{
			LOG_ERROR << "Connection ID not found for BroadCast2PlayerMessage, session ID: " << sessionId;
			continue;
		}
		g_gate_node->Send(sessionIt->second.conn_, request->body());
		//LOG_TRACE << "Broadcast message sent to session ID: " << sessionId;
	}
	///<<< END WRITING YOUR CODE
}
