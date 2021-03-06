#pragma once
#include "db_service.pb.h"
///<<< BEGIN WRITING YOUR CODE
#include "src/network/rpc_server.h"
#include "src/mysql_wrapper/mysql_database.h"

using namespace muduo;
using namespace muduo::net;

class MessageSyncRedisClient;

///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
class DbServiceImpl : public dbservice::DbService{
public:
///<<< BEGIN WRITING YOUR CODE
	using MysqlClientPtr = std::shared_ptr<MysqlDatabase>;
	using PbSyncRedisClientPtr = std::shared_ptr<MessageSyncRedisClient>;

	static DbServiceImpl& GetSingleton()
	{
		thread_local DbServiceImpl singleton;
		return singleton;
	}

	void set_player_mysql_client(MysqlClientPtr& ptr)
	{
		database_ = ptr;
	}

	void set_redis_client(PbSyncRedisClientPtr& ptr)
	{
		redis_ = ptr;
	}
private:
	MysqlClientPtr database_;
	PbSyncRedisClientPtr redis_;
///<<< END WRITING YOUR CODE
public:
    void Login(::google::protobuf::RpcController* controller,
        const dbservice::LoginRequest* request,
        dbservice::LoginResponse* response,
        ::google::protobuf::Closure* done)override;

    void CreatePlayer(::google::protobuf::RpcController* controller,
        const dbservice::CreatePlayerRequest* request,
        dbservice::CreatePlayerResponse* response,
        ::google::protobuf::Closure* done)override;

    void EnterGame(::google::protobuf::RpcController* controller,
        const dbservice::EnterGameRequest* request,
        dbservice::EnterGameResponse* response,
        ::google::protobuf::Closure* done)override;

};