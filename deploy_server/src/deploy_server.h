#ifndef DEPLOY_SERVER_SRCDEPLOY_SERVER_H_
#define DEPLOY_SERVER_SRCDEPLOY_SERVER_H_

#include "muduo/net/InetAddress.h"

#include "src/game_logic/timer_task/timer_task.h"
#include "src/mysql_wrapper/mysql_database.h"
#include "src/game_config/deploy_json.h"
#include "src/redis_client/redis_client.h"
#include "src/reuse_game_id/reuse_game_id.h"
#include "src/network/rpc_server.h"
#include "src/network/rpc_connection_event.h"
#include "src/service/deploy_service.h"

namespace deploy
{
    class DeployServer : public Receiver<DeployServer>
    {
    public:
        using MysqlClientPtr = std::shared_ptr<MysqlDatabase>;
        using PbSyncRedisClientPtr = std::shared_ptr<MessageSyncRedisClient>;

        DeployServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listen_addr);

        MysqlClientPtr& player_mysql_client() { return db_; }
        ReuseGsId& reuse_game_id() { return reuse_id_; }

        void Start();

        void RegisterService(::google::protobuf::Service*);

        uint32_t CreateGSId();

        void LoadGSDb();
        void SaveGSDb();

        void OnDisConnected(const muduo::net::TcpConnectionPtr& conn);
        void LogReuseInfo();
   
        void receive(const OnBeConnectedEvent& es);
    private:
        void InitGroupDb();

        template<typename DbRow>
        void InitRegionDb(uint32_t begin_port, uint32_t server_size )
        {
            DbRow sd;
            std::string sql = "select * from " + sd.GetTypeName() + " LIMIT 1";
            auto q_result = db_->QueryOne(sql);
            if (nullptr != q_result)
            {
                return;
            }
            auto& nomoral_ip = DeployConfig::GetSingleton().deploy_info().ip();

            uint32_t region_size = 0;
            uint32_t region_id = 0;
   
            sd.set_ip(nomoral_ip);
            sd.set_region_id(region_id);

            for (uint32_t i = 0; i < server_size; ++i)
            {
                if (region_size++ % 10 == 0)
                {
                    sd.set_region_id(++region_id);
                }
                sd.set_port(i + begin_port);
                db_->SaveOne(sd);
            }
        }

        template<typename DbRow>
		void InitRegionServer(uint32_t begin_port, uint32_t server_size)
		{
            DbRow sd;
			std::string sql = "select * from " + sd.GetTypeName() + " LIMIT 1";
			auto q_result = db_->QueryOne(sql);
			if (nullptr != q_result)
			{
				return;
			}
			auto& nomoral_ip = DeployConfig::GetSingleton().deploy_info().ip();

			uint32_t region_size = 0;
			uint32_t region_id = 0;

			sd.set_ip(nomoral_ip);

			for (uint32_t i = 0; i < server_size; ++i)
			{
				sd.set_port(i + begin_port);
				db_->SaveOne(sd);
			}
		}

		template<typename DbRow>
		void InitGroupDb(uint32_t begin_port, uint32_t server_size)
		{
			DbRow sd;
			std::string sql = "select * from " + sd.GetTypeName() + " LIMIT 1";
			auto q_result = db_->QueryOne(sql);
			if (nullptr != q_result)
			{
				return;
			}
			auto& nomoral_ip = DeployConfig::GetSingleton().deploy_info().ip();

			uint32_t region_size = 0;
			uint32_t group_id = 0;

			sd.set_ip(nomoral_ip);
			sd.set_group_id(group_id);

			for (uint32_t i = 0; i < server_size; ++i)
			{
				if (region_size++ % 10 == 0)
				{
					sd.set_group_id(++group_id);
				}
				sd.set_port(i + begin_port);
				db_->SaveOne(sd);
			}
		}

   
        muduo::net::RpcServer server_;
        MysqlClientPtr db_;   
        std::string redis_ip_ = "127.0.0.1";
        ReuseGsId reuse_id_;
        TimerTask scan_over_timer_;

        DeployServiceImpl impl_;
    };
}//namespace deploy

extern deploy::DeployServer* g_deploy_server;

#endif // !DEPLOY_SERVER_SRCDEPLOY_SERVER_H_
