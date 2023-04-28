#pragma once

#include "src/network/codec/codec.h"

#include "muduo/base/noncopyable.h"
#include "muduo/net/EventLoop.h"

#include "src/network/codec/dispatcher.h"
#include "src/network/rpc_msg_route.h"
#include "src/network/rpc_client.h"
#include "src/network/gate_player_list.h"
#include "src/util/snow_flake.h"

#include "database_service.pb.h"
#include "c2gate.pb.h"
#include "login_service.pb.h"
#include "controller_service.pb.h"
#include "game_service.pb.h"

using namespace muduo;
using namespace muduo::net;

using RpcClientMessagePtr = std::shared_ptr<ClientRequest>;

class ClientReceiver : muduo::noncopyable
{
public:

    ClientReceiver(ProtobufCodec& codec, ProtobufDispatcher& dispatcher);

    RpcClientPtr& get_login_node();
    RpcClientPtr& get_login_node(uint64_t session_id);
    uint32_t find_valid_login_node_id(uint64_t session_id);
    ProtobufCodec& codec() { return codec_; };

    void OnConnection(const muduo::net::TcpConnectionPtr& conn);

    void Send2Client(muduo::net::TcpConnectionPtr& conn, const ::google::protobuf::Message& messag) { codec_.send(conn, messag); }

    //client to gate 
	void OnRpcClientMessage(const muduo::net::TcpConnectionPtr& conn,
		const RpcClientMessagePtr& message,
		muduo::Timestamp);

    inline uint64_t tcp_session_id(const muduo::net::TcpConnectionPtr& conn) { return boost::any_cast<uint64_t>(conn->getContext()); }

    void Tip(const muduo::net::TcpConnectionPtr& conn, uint32_t tip_id);
private:
    ProtobufCodec& codec_;
    ProtobufDispatcher& dispatcher_;   
};