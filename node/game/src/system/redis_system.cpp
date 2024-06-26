#include "redis_system.h"

#include "muduo/net/EventLoop.h"

#include "player_common_system.h"
#include "thread_local/thread_local_storage_game.h"

using namespace muduo;
using namespace muduo::net;

void RedisSystem::Init(muduo::net::InetAddress& server_addr)
{
    hiredis_ = std::make_unique<HiredisPtr::element_type>(EventLoop::getEventLoopOfCurrentThread(), server_addr);
    hiredis_->connect();

    tls_game.player_redis() = std::make_unique<PlayerRedis::element_type>(*hiredis_);
    tls_game.player_redis()->SetLoadCallback(PlayerCommonSystem::OnPlayerAsyncLoaded);
    tls_game.player_redis()->SetSaveCallback(PlayerCommonSystem::OnPlayerAsyncSaved);
}