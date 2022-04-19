#include "rgscene_rg.h"
#include "src/network/rpc_closure.h"
///<<< BEGIN WRITING YOUR CODE


#include "src/game_config/mainscene_config.h"

#include "src/game_logic/scene/scene_factories.h"
#include "src/game_logic/scene/servernode_sys.h"
#include "src/game_logic/scene/scene.h"
#include "src/game_logic/game_registry.h"
#include "src/game_logic/comp/gs_scene_comp.hpp"
#include "src/network/server_component.h"
#include "src/network/gs_node.h"

#include "gs_node.pb.h"

using namespace muduo;
using namespace muduo::net;

using GsStubPtr = std::unique_ptr <common::RpcStub<gsservice::GsService_Stub>>;
///<<< END WRITING YOUR CODE

using namespace common;
namespace regionservcie{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE

///<<<rpc begin
void RgServiceImpl::StartCrossMainGS(::google::protobuf::RpcController* controller,
    const regionservcie::StartCrossMainGSRequest* request,
    regionservcie::StartCrossMainGSResponse* response,
    ::google::protobuf::Closure* done)
{
    AutoRecycleClosure d(done);
///<<< BEGIN WRITING YOUR CODE StartCrossMainGS
	InetAddress rpc_client_peer_addr(request->rpc_client().ip(), request->rpc_client().port());
	InetAddress rpc_server_peer_addr(request->rpc_server().ip(), request->rpc_server().port());
	entt::entity gs_entity{ entt::null };
	for (auto e : reg.view<RpcServerConnection>())
	{
		if (reg.get<RpcServerConnection>(e).conn_->peerAddress().toIpPort() != rpc_client_peer_addr.toIpPort())
		{
			continue;
		}
		gs_entity = e;
		break;
	}
	if (gs_entity == entt::null)
	{
		//todo
		LOG_INFO << "game connection not found " << request->gs_node_id();
		return;
	}

	auto c = reg.get<RpcServerConnection>(gs_entity);
	GsNodePtr gs = std::make_shared<GsNode>(c.conn_);
	gs->node_info_.set_node_id(request->gs_node_id());
	gs->node_info_.set_node_type(GAME_SERVER_NODE_TYPE);
	MakeGSParam make_gs_p;
	make_gs_p.node_id_ = request->gs_node_id();
	AddMainSceneNodeCompnent(gs_entity, make_gs_p);
	reg.emplace<InetAddress>(gs_entity, rpc_server_peer_addr);
	reg.emplace<GsNodePtr>(gs_entity, gs);
	reg.emplace<GsStubPtr>(gs_entity, std::make_unique<GsStubPtr::element_type>(boost::any_cast<muduo::net::RpcChannelPtr>(c.conn_->getContext())));

	auto& config_all = mainscene_config::GetSingleton().all();
	MakeGSSceneP create_scene_param;
	create_scene_param.server_entity_ = gs_entity;
	for (int32_t i = 0; i < config_all.data_size(); ++i)
	{
		create_scene_param.scene_confid_ = config_all.data(i).id();
		auto scene_entity = g_scene_sys->MakeSceneGSScene(create_scene_param);
		if (!reg.valid(scene_entity))
		{
			continue;
		}
		auto scene_info = response->add_scenes_info();
		scene_info->set_scene_confid(reg.get<SceneConfigId>(scene_entity));
		scene_info->set_scene_id(reg.get<Guid>(scene_entity));
	}

	LOG_INFO << "game connected " << request->gs_node_id();
///<<< END WRITING YOUR CODE StartCrossMainGS
}

void RgServiceImpl::StartCrossRoomGS(::google::protobuf::RpcController* controller,
    const regionservcie::StartCrossRoomGSRequest* request,
    regionservcie::StartCrossRoomGSResponse* response,
    ::google::protobuf::Closure* done)
{
    AutoRecycleClosure d(done);
///<<< BEGIN WRITING YOUR CODE StartCrossRoomGS
///<<< END WRITING YOUR CODE StartCrossRoomGS
}

///<<<rpc end
}// namespace regionservcie
