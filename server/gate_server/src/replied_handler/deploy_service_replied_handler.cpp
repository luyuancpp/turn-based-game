#include "deploy_service_replied_handler.h"
#include "src/network/codec/dispatcher.h"

///<<< BEGIN WRITING YOUR CODE
#include "src/gate_server.h"
#include "src/thread_local/gate_thread_local_storage.h"
#include "src/util/snow_flake.h"

extern ServerSequence32 g_server_sequence_;
///<<< END WRITING YOUR CODE
extern ProtobufDispatcher g_response_dispatcher;


void InitDeployServiceGetNodeInfoRepliedHandler()
{
	g_response_dispatcher.registerMessageCallback<NodeInfoResponse>(std::bind(&OnDeployServiceGetNodeInfoRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	g_response_dispatcher.registerMessageCallback<StartGsResponse>(std::bind(&OnDeployServiceStartGsRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	g_response_dispatcher.registerMessageCallback<GsNodeIdResponse>(std::bind(&OnDeployServiceGetGsNodeIdRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void OnDeployServiceGetNodeInfoRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<NodeInfoResponse>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
    auto& server_node_data = replied->info();
    g_gate_node->set_servers_info_data(server_node_data);
    g_server_sequence_.set_node_id(g_gate_node->gate_node_id());
    g_gate_node->StartServer();
///<<< END WRITING YOUR CODE
}

void OnDeployServiceStartGsRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<StartGsResponse>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void OnDeployServiceGetGsNodeIdRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<GsNodeIdResponse>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
    //for (const auto& replied_it : replied->login_db().login_nodes())
    //{
    //    //todo
    //    if (replied_it.id() != 1)
    //    {
    //        continue;
    //    }
    //    auto& login_info = replied_it;
    //    auto it = gate_tls.login_nodes().emplace(login_info.id(), LoginNode());
    //    if (!it.second)
    //    {
    //        LOG_ERROR << "login server connected" << login_info.DebugString();
    //        return;
    //    }
    //    InetAddress login_addr(login_info.ip(), login_info.port());
    //    auto& login_node = it.first->second;
    //    login_node.login_session_ = std::make_unique<RpcClientPtr::element_type>(g_gate_node->loop(), login_addr);
    //    login_node.login_session_->registerService(&g_gate_node->gate_service_hanlder());
    //    login_node.login_session_->connect();
    //}
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
