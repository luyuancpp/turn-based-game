#include "gslogin_server_player.h"
#include "src/game_logic/game_registry.h"
#include "src/network/message_system.h"
///<<< BEGIN WRITING YOUR CODE

#include "muduo/base/Logging.h"

#include "src/comp/player_list.h"
#include "src/game_logic/scene/scene.h"
#include "src/network/gate_node.h"
#include "src/network/message_system.h"
#include "src/network/session.h"
#include "src/network/gate_node.h"
#include "src/system/player_common_system.h"

#include "component_proto/player_login_comp.pb.h"
#include "component_proto/player_network_comp.pb.h"
///<<< END WRITING YOUR CODE

///<<<rpc begin
void ServerPlayerLoginServiceImpl::LoginMs2Gs(entt::entity player,
    const ::Ms2GsLoginRequest* request,
    ::google::protobuf::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE
 // 这个人除了断线重连，重新上线，目前不会更换gate

    if (request->enter_gs_type() == LOGIN_NONE)//登录，不是普通切换场景
    {
        return;
    }
    auto gate_node_id = node_id(request->session_id());
    auto gate_it = g_gate_nodes->find(gate_node_id);
    if (gate_it == g_gate_nodes->end())//test
    {
        LOG_ERROR << "EnterSceneMs2Gs gate not found " << gate_node_id;
        return;
    }
    auto p_gate = registry.try_get<GateNodePtr>(gate_it->second);
    if (nullptr == p_gate)
    {
        LOG_ERROR << "EnterSceneMs2Gs gate not found " << gate_node_id;
        return;
    }
    g_gate_sessions->emplace(request->session_id(), player);
    registry.emplace_or_replace<GateSession>(player).set_session_id(request->session_id());//登录更新gate
    registry.emplace_or_replace<GateNodeWPtr>(player, *p_gate);
    PlayerCommonSystem::OnPlayerLogin(player, request->enter_gs_type());
///<<< END WRITING YOUR CODE
}

///<<<rpc end
