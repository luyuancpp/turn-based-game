#include "redis.h"

#include "muduo/net/EventLoop.h"

#include "player/player_node.h"
#include "thread_local/storage_game.h"

using namespace muduo;
using namespace muduo::net;

void RedisSystem::Init(muduo::net::InetAddress& server_addr)
{
    hiredis_ = std::make_unique<HiredisPtr::element_type>(EventLoop::getEventLoopOfCurrentThread(), server_addr);
    hiredis_->connect();

    tls_game.player_redis_ = std::make_unique<PlayerRedis::element_type>(*hiredis_);
    tls_game.player_redis_->SetLoadCallback(PlayerNodeSystem::OnPlayerAsyncLoaded);
    tls_game.player_redis_->SetSaveCallback(PlayerNodeSystem::OnPlayerAsyncSaved);
}