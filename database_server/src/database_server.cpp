#include "database_server.h"

#include "deploy_json.h"
#include "service/deploy_service_service.h"
#include "src/handler/replied_dispathcer.h"
#include "src/network/node_info.h"

DatabaseServer* g_database_node{nullptr};

DatabaseServer::DatabaseServer(muduo::net::EventLoop* loop)
    : loop_(loop),
        database_(std::make_shared<MysqlClientPtr::element_type>()),
        redis_(std::make_shared<PbSyncRedisClientPtr::element_type>()){}

DatabaseServer::~DatabaseServer()
{
    tls.dispatcher.sink<OnConnected2ServerEvent>().disconnect<&DatabaseServer::Receive>(*this);
}

void DatabaseServer::Init()
{
    GameConfig::GetSingleton().Load("game.json");
    DeployConfig::GetSingleton().Load("deploy.json");
	void InitMessageInfo();
	InitMessageInfo();
	node_info_.set_node_type(kDatabaseNode);
	node_info_.set_launch_time(Timestamp::now().microSecondsSinceEpoch());
    InitRepliedCallback();
    ConnectDeploy();
}

void DatabaseServer::ConnectDeploy()
{
    const auto& deploy_info = DeployConfig::GetSingleton().deploy_info();
    InetAddress deploy_addr(deploy_info.ip(), deploy_info.port());
    deploy_session_ = std::make_unique<RpcClient>(loop_, deploy_addr);
    tls.dispatcher.sink<OnConnected2ServerEvent>().connect<&DatabaseServer::Receive>(*this);
    deploy_session_->connect();
}

void DatabaseServer::Start()
{
    database_->AddTable(account_database::default_instance());
    database_->AddTable(player_database::default_instance());
    static const uint64_t begin_guid = 10000000000;
    database_->set_auto_increment(player_database::default_instance(),
        GameConfig::GetSingleton().config_info().group_id() * begin_guid);
    database_->Init();

    server_->registerService(&impl_);
    server_->start();
}

void DatabaseServer::StartServer(const ::servers_info_data& info)
{
    auto& redis_info = info.redis_info();
    auto& my_node_info = info.database_info();
    InetAddress listenAddr(my_node_info.ip(), my_node_info.port());
    redis_->Connect(redis_info.ip(), redis_info.port(), 1, 1);
    database_->Connect(my_node_info);
    node_info_.set_node_id(my_node_info.id());
    server_ = std::make_shared<RpcServerPtr::element_type>(loop_, listenAddr);
    Start();
}

void DatabaseServer::Receive(const OnConnected2ServerEvent& es) const
{
    if (!es.conn_->connected())
    {
        return;
    }
    // started 
    if (nullptr != server_)
    {
        return;
    }
    ServerInfoRequest rq;
    rq.set_group(GameConfig::GetSingleton().config_info().group_id());
    deploy_session_->CallMethod(DeployServiceServerInfoMsgId, rq);
}



