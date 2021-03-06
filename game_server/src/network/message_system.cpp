#include "message_system.h"

#include "muduo/base/Logging.h"

#include "src/game_logic/game_registry.h"
#include "src/comp/player_list.h"
#include "src/network/gate_node.h"
#include "src/network/ms_node.h"
#include "src/pb/pbc/msgmap.h"

#include "gw_service.pb.h"
#include "ms_service.pb.h"
#include "component_proto/player_network_comp.pb.h"

void Send2Player(const google::protobuf::Message& message, Guid player_id)
{
	auto it = g_players->find(player_id);
	if (it == g_players->end())
	{
		LOG_DEBUG << "Send2Player player not found " << player_id;
		return;
	}
	Send2Player(message, it->second);
}

void Send2Player(const google::protobuf::Message& message, entt::entity player)
{
	if (!registry.valid(player))
	{
		return;
	}
	auto try_gate = registry.try_get<GateNodeWPtr>(player);
	if (nullptr == try_gate)
	{
		LOG_ERROR << "Send2Player player gate not found " << registry.get<Guid>(player);
		return;
	}
	auto message_it = g_msgid.find(message.GetDescriptor()->full_name());
	if (message_it == g_msgid.end())
	{
		LOG_ERROR << "Send2Player message id not found " << message.GetDescriptor()->full_name();
		return;
	}
	auto gate = (*try_gate).lock();
	if (nullptr == gate)
	{
		LOG_INFO << "Send2Player player gate not found " << registry.get<Guid>(player);
		return;
	}
	gwservice::GsPlayerMessageRequest msg_wrapper;
	msg_wrapper.mutable_msg()->set_msg_id(message_it->second);
	msg_wrapper.mutable_msg()->set_body(message.SerializeAsString());
	msg_wrapper.mutable_ex()->set_session_id(registry.get<GateSession>(player).session_id());
	gate->session_.Send(msg_wrapper);
}

void Send2Player(const google::protobuf::Message& message, EntityPtr& player)
{
    Send2Player(message, (entt::entity)player);
}

void Send2MsPlayer(const google::protobuf::Message& message, Guid player_id)
{
	auto it = g_players->find(player_id);
	if (it == g_players->end())
	{
		LOG_DEBUG << " Send2MsPlayer player not found " << player_id;
		return;
	}
	Send2MsPlayer(message, it->second);
}

void Send2MsPlayer(const google::protobuf::Message& message, entt::entity player)
{
	if (!registry.valid(player))
	{
		return;
	}
	auto message_it = g_msgid.find(message.GetDescriptor()->full_name());
	if (message_it == g_msgid.end())
	{
		LOG_ERROR << " Send2MsPlayer message id not found " << message.GetDescriptor()->full_name();
		return;
	}
	auto ms_node = registry.get<MsNodePtr>(player);
	if (nullptr == ms_node)
	{
		LOG_ERROR << "Send2MsPlayer player master not found " << registry.get<Guid>(player);
		return;
	}
	if (!ms_node->session_->connected())
	{
		LOG_ERROR << "Send2MsPlayer master disconnect" << registry.get<Guid>(player);
		return;
	}
	msservice::PlayerNodeServiceRequest msg_wrapper;
	msg_wrapper.mutable_msg()->set_msg_id(message_it->second);
	msg_wrapper.mutable_msg()->set_body(message.SerializeAsString());
	msg_wrapper.mutable_ex()->set_player_id(registry.get<Guid>(player));
	ms_node->session_->Send(msg_wrapper);
}

void Send2MsPlayer(const google::protobuf::Message& message, EntityPtr& player)
{
	Send2MsPlayer(message, (entt::entity)player);
}

void Send2Ms(const google::protobuf::Message& messag, uint32_t ms_node_id)
{
	auto ms_it = g_ms_nodes->find(ms_node_id);
	if (ms_it == g_ms_nodes->end())
	{
		LOG_ERROR << "Send2MsPlayer master not found" << ms_node_id;
		return;
	}
	ms_it->second->session_->Send(messag);
}

void Send2Gate(const google::protobuf::Message& messag, uint32_t gate_node_id)
{
	auto gate_it = g_gate_nodes->find(gate_node_id);
	if (gate_it == g_gate_nodes->end())
	{
		LOG_ERROR << "Send2Gate gate not found" << gate_node_id;
		return;
	}
	auto& gate_node = registry.get<GateNodePtr>(gate_it->second);
	gate_node->session_.Send(messag);
}

