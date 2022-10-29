#include "player_change_scene.h"

#include "src/game_logic/game_registry.h"
#include "src/game_logic/scene/scene.h"
#include "src/game_logic/tips_id.h"
#include "src/network/player_session.h"
#include "src/system/player_scene_system.h"


void PlayerChangeSceneSystem::InitChangeSceneQueue(entt::entity player)
{
	registry.emplace<PlayerMsChangeSceneQueue>(player);
}

uint32_t PlayerChangeSceneSystem::ChangeScene(entt::entity player, MsChangeSceneInfo&& change_info)
{
	GetPlayerCompnentMemberReturnError(change_scene_queue, PlayerMsChangeSceneQueue, kRetChangeScenePlayerQueueCompnentNull);
	CheckCondtion(change_scene_queue.full(), kRetChangeScenePlayerQueueCompnentFull);
	change_info.set_change_time(muduo::Timestamp::now().secondsSinceEpoch());//todo
	change_scene_queue.push_back(change_info);
	return kRetOK;
}

//当前服务器去计算当前的消息是不是同一个gs

uint32_t PlayerChangeSceneSystem::TryChangeSameGsScene(entt::entity player)
{
	GetPlayerCompnentReturnError(try_change_scene_queue, PlayerMsChangeSceneQueue, kRetChangeScenePlayerQueueCompnentNull);
	auto& change_scene_queue = try_change_scene_queue->change_scene_queue_;
	if (change_scene_queue.empty())
	{
		return kRetChangeScenePlayerQueueCompnentEmpty;
	}
	auto& change_info = change_scene_queue.front();
	auto to_scene = ScenesSystem::get_scene(change_info.scene_info().scene_id());
	if (entt::null == to_scene)//场景不存在了把消息删除,这个文件一定要注意这个队列各种异常情况
	{
		change_scene_queue.pop_front();//todo
		return kRetEnterSceneSceneNotFound;
	}
	LeaveSceneParam lp;
	lp.leaver_ = player;
	ScenesSystem::LeaveScene(lp);

	EnterSceneParam ep;
	ep.enterer_ = player;
	ep.scene_ = to_scene;
	ScenesSystem::EnterScene(ep);
	change_scene_queue.pop_front();//切换成功消息删除
	return kRetOK;
}

uint32_t PlayerChangeSceneSystem::Gs1SceneToGs2SceneInMyServer(entt::entity player)
{
    GetPlayerCompnentReturnError(try_change_scene_queue, PlayerMsChangeSceneQueue, kRetChangeScenePlayerQueueCompnentNull);
    auto& change_scene_queue = try_change_scene_queue->change_scene_queue_;
    if (change_scene_queue.empty())
    {
        return kRetChangeScenePlayerQueueCompnentEmpty;
    }
	auto& change_info = change_scene_queue.front();
	if (change_info.change_gs_status() == MsChangeSceneInfo::eLeaveGsScene)
	{
        LeaveSceneParam lp;
        lp.leaver_ = player;
        ScenesSystem::LeaveScene(lp);
	}
	else if (change_info.change_gs_status() == MsChangeSceneInfo::eLeaveGsSceneSucceed)
	{
        auto to_scene = ScenesSystem::get_scene(change_info.scene_info().scene_id());
        if (entt::null == to_scene)//场景不存在了把消息删除,这个文件一定要注意这个队列各种异常情况
        {
            change_scene_queue.pop_front();//todo
            return kRetEnterSceneSceneNotFound;
        }
        EnterSceneParam ep;
        ep.enterer_ = player;
        ep.scene_ = to_scene;
        ScenesSystem::EnterScene(ep);
		change_info.set_change_gs_status(MsChangeSceneInfo::eEnterGsScene);
	}
	else if (change_info.change_gs_status() == MsChangeSceneInfo::eEnterGsSceneSucceed)
	{
		change_scene_queue.pop_front();//todo
	}
	return kRetOK;
}

uint32_t PlayerChangeSceneSystem::TryPopFrontMsg(entt::entity player)
{
	GetPlayerCompnentMemberReturnError(change_scene_queue, PlayerMsChangeSceneQueue, kRetChangeScenePlayerQueueCompnentNull);
	if (change_scene_queue.empty())
	{
		return kRetOK;
	}
	return kRetOK;
}

void PlayerChangeSceneSystem::TryProcessChangeSceneQueue(entt::entity player)
{
	GetPlayerCompnentMemberReturnVoid(change_scene_queue, PlayerMsChangeSceneQueue);
    if (change_scene_queue.empty())
    {
        return;
    }
	auto& front_msg = change_scene_queue.front();
	if (front_msg.change_gs_type() == MsChangeSceneInfo::eSameGs)//同一个gs切换
	{
		TryChangeSameGsScene(player);//就算同gs,队列有消息也不能直接切换，
		return;
	}
	//同一个服务器不同gs切换
	if (front_msg.cross_server_type() == MsChangeSceneInfo::eDotnotCrossServer)
	{
        //正在切换
        //切换gs  存储完毕之后才能进入下一个场景
        //放到存储完毕切换场景的队列里面，如果等够足够时间没有存储完毕，可能就是服务器崩溃了,注意，是可能 
		Gs1SceneToGs2SceneInMyServer(player);
		return;
	}
}
