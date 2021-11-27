#include "gateway_server.h"

#include "src/game_config/deploy_json.h"
#include "src/server_common/deploy_rpcclient.h"

using namespace common;

gateway::GatewayServer* g_gateway_server = nullptr; 

namespace gateway
{

void GatewayServer::LoadConfig()
{
    GameConfig::GetSingleton().Load("game.json");
    DeployConfig::GetSingleton().Load("deploy.json");
}

void GatewayServer::InitNetwork()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_param();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_rpc_client_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    deploy_rpc_client_->subscribe<RegisterStubES>(deploy_stub_);
    deploy_rpc_client_->subscribe<RpcClientConnectionES>(*this);
    deploy_rpc_client_->connect();
}

void GatewayServer::StartServer(ServerInfoRpcRC cp)
{
    serverinfo_database_ = cp->s_resp_->info();
    auto& login_info = serverinfo_database_.login_info();
    InetAddress login_addr(login_info.ip(), login_info.port());
    login_rpc_client_ = std::make_unique<RpcClient>(loop_, login_addr);
    login_rpc_client_->connect();
    login_rpc_client_->subscribe<RegisterStubES>(gw2l_login_stub_);

    auto& master_info = serverinfo_database_.master_info();
    InetAddress master_addr(master_info.ip(), master_info.port());
    master_rpc_client_ = std::make_unique<RpcClient>(loop_, master_addr);
    master_rpc_client_->registerService(&ms2gw_service_impl_);
    master_rpc_client_->subscribe<RegisterStubES>(gw2ms_stub_);
    master_rpc_client_->subscribe<RpcClientConnectionES>(*this);
    master_rpc_client_->connect();        

    auto& myinfo = serverinfo_database_.gateway_info();
    InetAddress gateway_addr(myinfo.ip(), myinfo.port());
    server_ = std::make_unique<TcpServer>(loop_, gateway_addr, "gateway");
    server_->setConnectionCallback(
        std::bind(&GatewayServer::OnConnection, this, _1));
    server_->setMessageCallback(
        std::bind(&ProtobufCodec::onMessage, &codec_, _1, _2, _3));
    server_->start();
}

void GatewayServer::Register2Master()
{ 
    auto& master_local_addr = master_rpc_client_->local_addr();
    gw2ms::ConnectRequest request;
    request.mutable_rpc_client()->set_ip(master_local_addr.toIp());
    request.mutable_rpc_client()->set_port(master_local_addr.port());
    gw2ms_stub_.CallMethod(request, &gw2ms::Gw2msService_Stub::GwConnectMaster);
}

void GatewayServer::receive(const RpcClientConnectionES& es)
{
    if (!es.conn_->connected())
    {
        return;
    }

    if (IsSameAddr(es.conn_->peerAddress(), DeployConfig::GetSingleton().deploy_param()))
    {
        // started 
        if (nullptr != server_)
        {
            return;
        }
        ServerInfoRpcRC cp(std::make_shared<ServerInfoRpcClosure>());
        cp->s_reqst_.set_group(GameConfig::GetSingleton().config_info().group_id());
        deploy_stub_.CallMethod(
            &GatewayServer::StartServer,
            cp,
            this,
            &deploy::DeployService_Stub::ServerInfo);
    }
    else if (IsSameAddr(es.conn_->peerAddress(), serverinfo_database_.master_info()))
    {
        Register2Master();
    }
}

}//namespace gateway
