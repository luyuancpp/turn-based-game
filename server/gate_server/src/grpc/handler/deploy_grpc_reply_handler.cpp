#include "deploy_grpc_reply_handler.h"

#include "muduo/base/Logging.h"

#include "src/util/defer.h"

#include "src/grpc/async_client_call.h"
#include "src/network/deploy/deployclient.h"
#include "src/gate_server.h"

void AsyncCompleteGrpc()
{
    void* got_tag;
    bool ok = false;
    gpr_timespec tm;
    tm.tv_sec = 0;
    tm.tv_nsec = 1;
    if (CompletionQueue::GOT_EVENT != g_deploy_client->cq().AsyncNext(&got_tag, &ok, tm))
    {
        return;
    }

    std::unique_ptr<AsyncClientCall> call (static_cast<AsyncClientCall*>(got_tag));

    CHECK(ok);

    if (call->status.ok())
        g_gate_node->set_servers_info_data(call->reply.info());
    else
        LOG_INFO << "RPC failed" ;

}

void DeployGrpcReplyHandler()
{

}
