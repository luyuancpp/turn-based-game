#pragma once
#include "login_service.pb.h"
///<<< BEGIN WRITING YOUR CODE
#include "src/comp/account_player.h"
#include "src/game_logic/game_registry.h"
#include "src/network/rpc_closure.h"
#include "src/network/rpc_closure.h"
#include "src/network/rpc_stub.h"
#include "src/network/rpc_client.h"
#include "src/redis_client/redis_client.h"

#include "login_service.pb.h"
#include "db_service.pb.h"
#include "ms_service.pb.h"

///<<< END WRITING YOUR CODE
class LoginServiceImpl : public gw2l::LoginService{
public:
		///<<< BEGIN WRITING YOUR CODE
		using PlayerPtr = std::shared_ptr<AccountPlayer>;
		using LoginPlayersMap = std::unordered_map<std::string, PlayerPtr>;
		using ConnectionEntityMap = std::unordered_map<Guid, EntityPtr>;
		using LoginStubl2ms = RpcStub<msservice::MasterNodeService_Stub>;
		using LoginStubl2db = RpcStub<dbservice::DbService_Stub>;

		LoginServiceImpl(LoginStubl2ms& l2ms_login_stub,
			LoginStubl2db& l2db_login_stub);

		void set_redis_client(PbSyncRedisClientPtr& p) { redis_ = p; }

		using LoginAccountDbRpc = std::shared_ptr< RpcString<dbservice::LoginRequest, dbservice::LoginResponse, gw2l::LoginResponse>>;
		void LoginAccountDbReplied(LoginAccountDbRpc replied);

		using LoginAcountMsRpc = std::shared_ptr<RpcString<msservice::LoginAccountRequest, msservice::LoginAccountResponse, gw2l::LoginResponse>>;
		void LoginAccountMsReplied(LoginAcountMsRpc replied);

		using CreatePlayerRpcReplied = std::shared_ptr<RpcString<dbservice::CreatePlayerRequest, dbservice::CreatePlayerResponse, gw2l::CreatePlayerResponse>>;
		void CreatePlayerDbReplied(CreatePlayerRpcReplied replied);

		using EnterGameDbRpcReplied = std::shared_ptr<RpcString<dbservice::EnterGameRequest, dbservice::EnterGameResponse, gw2l::EnterGameResponse>>;
		void EnterGameDbReplied(EnterGameDbRpcReplied replied);

		using EnterGameMsRpc = std::shared_ptr<RpcString<msservice::EnterGameRequest, msservice::EnterGameResponese, gw2l::EnterGameResponse>>;
		void EnterGameReplied(EnterGameMsRpc replied);

		void EnterGame(Guid player_id,
			uint64_t connection_id,
			::gw2l::EnterGameResponse* response,
			::google::protobuf::Closure* done);

	private:
		void UpdateAccount(uint64_t connection_id, const ::account_database& a_d);

		PbSyncRedisClientPtr redis_;
		ConnectionEntityMap sessions_;
		LoginStubl2ms& ms_node_stub_;
		LoginStubl2db& l2db_login_stub_;
		///<<< END WRITING YOUR CODE
public:
    void Login(::google::protobuf::RpcController* controller,
        const gw2l::LoginRequest* request,
        gw2l::LoginResponse* response,
        ::google::protobuf::Closure* done)override;

    void CreatPlayer(::google::protobuf::RpcController* controller,
        const gw2l::CreatePlayerRequest* request,
        gw2l::CreatePlayerResponse* response,
        ::google::protobuf::Closure* done)override;

    void EnterGame(::google::protobuf::RpcController* controller,
        const gw2l::EnterGameRequest* request,
        gw2l::EnterGameResponse* response,
        ::google::protobuf::Closure* done)override;

    void LeaveGame(::google::protobuf::RpcController* controller,
        const gw2l::LeaveGameRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

    void Disconnect(::google::protobuf::RpcController* controller,
        const gw2l::DisconnectRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)override;

};