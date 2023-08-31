#include <gtest/gtest.h>

#include "src/common_type/common_type.h"
#include "src/game_logic/scene/scene.h"
#include "src/game_logic/thread_local/thread_local_storage.h"

#include "component_proto/gs_node_comp.pb.h"
#include "src/pb/pbc/component_proto/scene_comp.pb.h"

using GsNodePlayerInfoPtr = std::shared_ptr<GsNodePlayerInfo>;

std::size_t confid_scenelist_size = 50;
std::size_t per_scene_config_size = 2;

entt::entity CreateMainSceneNode()
{
    const auto scene_entity = tls.registry.create();
    AddMainSceneNodeComponent(scene_entity);
    return scene_entity;
}

TEST(GS, CreateMainScene)
{
    const ScenesSystem sm;
    CreateGsSceneP create_gs_scene_param;
    const auto server_entity1 = CreateMainSceneNode();
    create_gs_scene_param.node_ = server_entity1;
    for (uint32_t i = 0; i < confid_scenelist_size; ++i)
    {
        create_gs_scene_param.scene_confid_ = i;
        for (uint32_t j = 0; j < per_scene_config_size; ++j)
        {
            sm.CreateScene2Gs(create_gs_scene_param);
        }
        EXPECT_EQ(sm.scenes_size(i), per_scene_config_size);
    }
    EXPECT_EQ(sm.scenes_size(), confid_scenelist_size * per_scene_config_size);
    EXPECT_EQ(sm.scenes_size(), confid_scenelist_size * per_scene_config_size);
}

TEST(GS, CreateScene2Sever)
{
    const ScenesSystem sm;
    const auto server_entity1 = CreateMainSceneNode();
    const auto server_entity2 = CreateMainSceneNode();

    CreateGsSceneP create_gs_scene_param1;
    CreateGsSceneP create_gs_scene_param2;

    create_gs_scene_param1.scene_confid_ = 2;
    create_gs_scene_param1.node_ = server_entity1;

    create_gs_scene_param2.scene_confid_ = 3;
    create_gs_scene_param2.node_ = server_entity2;

    sm.CreateScene2Gs(create_gs_scene_param1);
    sm.CreateScene2Gs(create_gs_scene_param2);

    auto& servercomp1 = tls.registry.get<ServerComp>(server_entity1);
 
    auto& servercomp2 = tls.registry.get<ServerComp>(server_entity2);

    EXPECT_EQ(1, servercomp1.GetScenesSize());

    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param1.scene_confid_));

    EXPECT_EQ(1, servercomp2.GetScenesSize());

    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param2.scene_confid_));
    EXPECT_EQ(2, sm.scenes_size());
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());
}

TEST(GS, DestroyScene)
{
    ScenesSystem const sm;

    const auto server_entity1 = CreateMainSceneNode();

    CreateGsSceneP create_gs_scene_param1;
    create_gs_scene_param1.node_ = server_entity1;
    const auto scene_entity = sm.CreateScene2Gs(create_gs_scene_param1);

    EXPECT_EQ(1, sm.scenes_size());
    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param1.scene_confid_));
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());

    const auto& server_comp = tls.registry.get<ServerComp>(server_entity1);
    EXPECT_EQ(1, server_comp.GetScenesSize());

    DestroySceneParam destroy_scene_param;
    destroy_scene_param.node_ = server_entity1;
    destroy_scene_param.scene_ = scene_entity;
    sm.DestroyScene(destroy_scene_param);
    EXPECT_TRUE(sm.IsSceneEmpty());
    EXPECT_FALSE(sm.HasConfigScene(create_gs_scene_param1.scene_confid_));
    EXPECT_TRUE(server_comp.IsSceneEmpty());
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());
    EXPECT_FALSE(tls.registry.valid(scene_entity));
}

TEST(GS, DestroySever)
{
    ScenesSystem sm;

    auto server_entity1 = CreateMainSceneNode();
    auto server_entity2 = CreateMainSceneNode();

    CreateGsSceneP create_gs_scene_param1;
    CreateGsSceneP create_gs_scene_param2;
    create_gs_scene_param1.scene_confid_ = 3;
    create_gs_scene_param1.node_ = server_entity1;

    create_gs_scene_param2.scene_confid_ = 2;
    create_gs_scene_param2.node_ = server_entity2;

    auto scene_id1 = sm.CreateScene2Gs(create_gs_scene_param1);
    auto scene_id2 = sm.CreateScene2Gs(create_gs_scene_param2);

    EXPECT_EQ(1, tls.registry.get<ServerComp>(server_entity1).GetScenesSize());
    EXPECT_EQ(1, tls.registry.get<ServerComp>(server_entity2).GetScenesSize());

    EXPECT_EQ(2, sm.scenes_size());
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());

    DestroyServerParam destroy_server_param;
    destroy_server_param.node_ = server_entity1;
    sm.DestroyServer(destroy_server_param);

    EXPECT_FALSE(tls.registry.valid(server_entity1));
    EXPECT_FALSE(tls.registry.valid(scene_id1));
    EXPECT_TRUE(tls.registry.valid(server_entity2));
    EXPECT_TRUE(tls.registry.valid(scene_id2));

    EXPECT_EQ(1, tls.registry.get<ServerComp>(server_entity2).GetScenesSize());
    EXPECT_EQ(1, sm.scenes_size());
    EXPECT_EQ(0, sm.scenes_size(create_gs_scene_param1.scene_confid_));
    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param2.scene_confid_));

    destroy_server_param.node_ = server_entity2;
    sm.DestroyServer(destroy_server_param);

    EXPECT_EQ(0, sm.scenes_size());
    EXPECT_FALSE(tls.registry.valid(server_entity1));
    EXPECT_FALSE(tls.registry.valid(scene_id1));
    EXPECT_FALSE(tls.registry.valid(server_entity2));
    EXPECT_FALSE(tls.registry.valid(scene_id2));

    EXPECT_EQ(0, sm.scenes_size(create_gs_scene_param1.scene_confid_));
    EXPECT_EQ(0, sm.scenes_size(create_gs_scene_param2.scene_confid_));
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());
}

TEST(GS, ServerScene2Sever)
{
    ScenesSystem sm;

    const auto server_entity1 = CreateMainSceneNode();

    const auto server_entity2 = CreateMainSceneNode();
    CreateGsSceneP create_gs_scene_param1;
    CreateGsSceneP create_gs_scene_param2;

    create_gs_scene_param1.scene_confid_ = 3;
    create_gs_scene_param1.node_ = server_entity1;

    create_gs_scene_param2.scene_confid_ = 2;
    create_gs_scene_param2.node_ = server_entity2;

    const auto scene_entity1 = sm.CreateScene2Gs(create_gs_scene_param1);
    const auto scene_entity2 = sm.CreateScene2Gs(create_gs_scene_param2);
    EXPECT_EQ(1, tls.registry.get<ServerComp>(server_entity1).GetScenesSize());

    EXPECT_EQ(1, tls.registry.get<ServerComp>(server_entity2).GetScenesSize());

    EXPECT_EQ(2, sm.scenes_size());
    EXPECT_EQ(sm.scenes_size(), sm.scenes_size());

    MoveServerScene2ServerSceneP move_scene_param;
    move_scene_param.src_node_ = server_entity1;
    move_scene_param.dest_node_ = server_entity2;
    sm.MoveServerScene2ServerScene(move_scene_param);

    EXPECT_TRUE(tls.registry.valid(server_entity1));
    EXPECT_TRUE(tls.registry.valid(scene_entity1));
    EXPECT_TRUE(tls.registry.valid(server_entity2));
    EXPECT_TRUE(tls.registry.valid(scene_entity2));

    EXPECT_EQ(0, tls.registry.get<ServerComp>(server_entity1).GetScenesSize());
    EXPECT_EQ(2, tls.registry.get<ServerComp>(server_entity2).GetScenesSize());
    EXPECT_EQ(2, sm.scenes_size());
    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param1.scene_confid_));
    EXPECT_EQ(1, sm.scenes_size(create_gs_scene_param2.scene_confid_));

}

TEST(GS, PlayerLeaveEnterScene)
{
    const ScenesSystem sm;

    auto server_entity1 = CreateMainSceneNode();

    auto server_entity2 = CreateMainSceneNode();

    CreateGsSceneP create_gs_scene_param1;
    CreateGsSceneP create_gs_scene_param2;

    create_gs_scene_param1.scene_confid_ = 3;
    create_gs_scene_param1.node_ = server_entity1;

    create_gs_scene_param2.scene_confid_ = 2;
    create_gs_scene_param2.node_ = server_entity2;

    auto scene_id1 = sm.CreateScene2Gs(create_gs_scene_param1);
    auto scene_id2 = sm.CreateScene2Gs(create_gs_scene_param2);

    EnterSceneParam enter_param1;
    enter_param1.scene_ = scene_id1;
    
    EnterSceneParam enter_param2;
    enter_param2.scene_ = scene_id2;

    uint32_t player_size = 100;
    EntitySet player_entities_set1;
    EntitySet player_entities_set2;
    for (uint32_t i = 0; i < player_size; ++i)
    {
        auto pe = tls.registry.create();
        
        if (i % 2 == 0)
        {
            player_entities_set1.emplace(pe);
            enter_param1.enterer_ = pe;
            sm.EnterScene(enter_param1);
        }
        else
        {
            player_entities_set2.emplace(pe);
            enter_param2.enterer_ = pe;
            sm.EnterScene(enter_param2);
        }
    }

    auto& scenes_players1 = tls.registry.get<ScenePlayers>(scene_id1);
    auto& scenes_players2 = tls.registry.get<ScenePlayers>(scene_id2);
    for (auto&it : player_entities_set1)
    {
        EXPECT_TRUE(scenes_players1.find(it) != scenes_players1.end());
        EXPECT_TRUE(tls.registry.get<SceneEntity>(it).scene_entity_ == scene_id1);
    }
    for (auto& it : player_entities_set2)
    {
        EXPECT_TRUE(scenes_players2.find(it) != scenes_players2.end());
        EXPECT_TRUE(tls.registry.get<SceneEntity>(it).scene_entity_ == scene_id2);
    }
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity1)->player_size(), player_size / 2);
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity2)->player_size(), player_size / 2);
    LeaveSceneParam leave_param1;
    for (auto& it : player_entities_set1)
    {
        leave_param1.leaver_ = it;
        sm.LeaveScene(leave_param1);
        EXPECT_FALSE(scenes_players1.find(it) != scenes_players1.end());
        EXPECT_EQ(tls.registry.try_get<SceneEntity>(it), nullptr);
    }
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity1)->player_size(), 0);

    LeaveSceneParam leave_param2;
    for (auto& it : player_entities_set2)
    {
        leave_param2.leaver_ = it;
        sm.LeaveScene(leave_param2);
        EXPECT_FALSE(scenes_players2.find(it) != scenes_players2.end());
        EXPECT_EQ(tls.registry.try_get<SceneEntity>(it), nullptr);
    }
    
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity2)->player_size(), 0);
    auto& scenes_players11 = tls.registry.get<ScenePlayers>(scene_id1);
    auto& scenes_players22 = tls.registry.get<ScenePlayers>(scene_id2);
    EXPECT_TRUE(scenes_players11.empty());
    EXPECT_TRUE(scenes_players22.empty());
}

TEST(GS, MainTainWeightRoundRobinMainScene)
{
    tls.registry.clear();
    ScenesSystem sm;
    ServerNodeSystem snsys;
    EntitySet server_entities;
    uint32_t server_size = 2;
    uint32_t per_server_scene = 2;
    EntitySet scene_entities;

    for (uint32_t i = 0; i < server_size; ++i)
    {
        server_entities.emplace(CreateMainSceneNode());
    }

    CreateGsSceneP create_server_scene_param;
    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        create_server_scene_param.scene_confid_ = i;
        for (auto& it : server_entities)
        {
            create_server_scene_param.node_ = it;
            auto e = sm.CreateScene2Gs(create_server_scene_param);
            if (scene_entities.empty())
            {
                scene_entities.emplace(e);
            }
        }
    }

    uint32_t player_size = 1000;

    std::unordered_map<entt::entity, entt::entity> player_scene1;

    EnterSceneParam enter_param1;

    for (uint32_t i = 0; i < player_size; ++i)
    {
        for (auto it : scene_entities)
        {
            auto p_e = tls.registry.create();
            enter_param1.enterer_ = p_e;
            enter_param1.scene_ = it;
            player_scene1.emplace(enter_param1.enterer_, enter_param1.scene_);
            sm.EnterScene(enter_param1);
        }
    }

    ServerStateParam maintain;
    maintain.node_entity_ = *server_entities.begin();
    maintain.server_state_ = ServerState::kMainTain;
    snsys.set_server_state(maintain);

    uint32_t scene_config_id0 = 0;
    uint32_t scene_config_id1 = 1;
    GetSceneParam weight_round_robin_scene;
    weight_round_robin_scene.scene_confid_ = scene_config_id0;
    for (uint32_t i = 0; i < player_size; ++i)
    {
        auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
        EXPECT_TRUE(can_enter != entt::null);
    }
}

TEST(GS, CompelToChangeScene)
{
    ScenesSystem sm;

    auto server_entity1 = CreateMainSceneNode();
    auto server_entity2 = CreateMainSceneNode();

    CreateGsSceneP server1_param;
    CreateGsSceneP server2_param;

    server1_param.scene_confid_ = 2;
    server1_param.node_ = server_entity1;

    server2_param.scene_confid_ = 2;
    server2_param.node_ = server_entity2;

    auto scene_id1 = sm.CreateScene2Gs(server1_param);
    auto scene_id2 = sm.CreateScene2Gs(server2_param);

    EnterSceneParam enter_param1;
    enter_param1.scene_ = scene_id1;

    EnterSceneParam enter_param2;
    enter_param2.scene_ = scene_id2;

    uint32_t player_size = 100;
    EntitySet player_entities_set1;
    EntitySet player_entities_set2;
    for (uint32_t i = 0; i < player_size; ++i)
    {
        auto pe = tls.registry.create();
        player_entities_set1.emplace(pe);
        enter_param1.enterer_ = pe;
        sm.EnterScene(enter_param1);
    }

    CompelChangeSceneParam compel_change_param1;
    compel_change_param1.new_server_ = server_entity2;
    compel_change_param1.scene_confid_ = server2_param.scene_confid_;
    for (auto& it : player_entities_set1)
    {
        compel_change_param1.player_ = it;
        sm.CompelToChangeScene(compel_change_param1);
        EXPECT_TRUE(tls.registry.try_get<SceneEntity>(it)->scene_entity_ == scene_id2);
    }
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity1)->player_size(), 0);
    EXPECT_EQ(tls.registry.get<GsNodePlayerInfoPtr>(server_entity2)->player_size(), player_entities_set1.size());
    auto& scenes_players11 = tls.registry.get<ScenePlayers>(scene_id1);
    auto& scenes_players22 = tls.registry.get<ScenePlayers>(scene_id2);
    EXPECT_TRUE(scenes_players11.empty());
    EXPECT_EQ(scenes_players22.size(), player_entities_set1.size());
}


TEST(GS, CrashWeightRoundRobinMainScene)
{
    ScenesSystem sm;
    ServerNodeSystem snsys;
    EntitySet server_entities;
    uint32_t server_size = 2;
    uint32_t per_server_scene = 2;

    EntitySet scene_entities;

    for (uint32_t i = 0; i < server_size; ++i)
    {
        server_entities.emplace(CreateMainSceneNode( ));
    }

    CreateGsSceneP create_server_scene_param;
    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        create_server_scene_param.scene_confid_ = i;
        for (auto& it : server_entities)
        {
            create_server_scene_param.node_ = it;
            auto e = sm.CreateScene2Gs(create_server_scene_param);
            if (scene_entities.empty())
            {
                scene_entities.emplace(e);
            }
        }
    }

    uint32_t player_size = 1000;

    std::unordered_map<entt::entity, entt::entity> player_scene1;

    EnterSceneParam enter_param1;

    for (uint32_t i = 0; i < player_size; ++i)
    {
        for (auto it : scene_entities)
        {
            auto p_e = tls.registry.create();
            enter_param1.enterer_ = p_e;
            enter_param1.scene_ = it;
            player_scene1.emplace(enter_param1.enterer_, enter_param1.scene_);
            sm.EnterScene(enter_param1);
        }
    }

    ServerStateParam crash1;
    crash1.node_entity_ = *server_entities.begin();
    crash1.server_state_ = ServerState::kCrash;
    snsys.set_server_state(crash1);

    uint32_t scene_config_id0 = 0;
    uint32_t scene_config_id1 = 1;
    GetSceneParam weight_round_robin_scene;
    weight_round_robin_scene.scene_confid_ = scene_config_id0;
    for (uint32_t i = 0; i < player_size; ++i)
    {
        auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
        EXPECT_TRUE(can_enter != entt::null);
    }

}

//崩溃时候的消息不能处理
TEST(GS, CrashMovePlayer2NewServer)
{
    ScenesSystem sm;
    ServerNodeSystem snsys;
    EntitySet server_entities;
    uint32_t server_size = 2;
    uint32_t per_server_scene = 2;
    EntitySet scene_entities;
    entt::entity first_scene_id = entt::null;

    for (uint32_t i = 0; i < server_size; ++i)
    {
        server_entities.emplace(CreateMainSceneNode());
    }

    CreateGsSceneP create_server_scene_param;
    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        create_server_scene_param.scene_confid_ = i;
        for (auto& it : server_entities)
        {
            create_server_scene_param.node_ = it;
            auto e = sm.CreateScene2Gs(create_server_scene_param);
            scene_entities.emplace(e);
            if (first_scene_id == entt::null)
            {
                first_scene_id = e;
            }
        }
    }

    uint32_t player_size = 1000;

    std::unordered_map<entt::entity, entt::entity> player_scene1;

    EnterSceneParam enter_param1;

    for (uint32_t i = 0; i < player_size; ++i)
    {
        auto p_e = tls.registry.create();
        enter_param1.enterer_ = p_e;
        enter_param1.scene_ = first_scene_id;
        player_scene1.emplace(enter_param1.enterer_, enter_param1.scene_);
        sm.EnterScene(enter_param1);
    }

    ServerStateParam crash1;
    crash1.node_entity_ = *server_entities.begin();
    crash1.server_state_ = ServerState::kCrash;
    snsys.set_server_state(crash1);

    ReplaceCrashServerParam replace_crash;
    replace_crash.cransh_server_ = *server_entities.begin();
    replace_crash.replace_server_ = *(++server_entities.begin());
    sm.ReplaceCrashServer(replace_crash);

    EXPECT_FALSE(tls.registry.valid(replace_crash.cransh_server_));
    server_entities.erase(replace_crash.cransh_server_);
    for (auto& it : server_entities)
    {
        auto& server_scene =  tls.registry.get<ServerComp>(it);
        EXPECT_EQ(server_scene.GetScenesSize(), scene_entities.size());
    }
    
}

TEST(GS, WeightRoundRobinMainScene)
{
    tls.registry.clear();
    ScenesSystem sm;
    ServerNodeSystem snsys;
    EntitySet server_entities;
    uint32_t server_size = 10;
    uint32_t per_server_scene = 10;
    for (uint32_t i = 0; i < server_size; ++i)
    {

        server_entities.emplace(CreateMainSceneNode());
    }

    CreateGsSceneP create_server_scene_param;

    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        create_server_scene_param.scene_confid_ = i;
        for (auto& it :server_entities)
        {
            create_server_scene_param.node_ = it;
            sm.CreateScene2Gs(create_server_scene_param);
        }        
    }

    auto enter_leave_lambda = [&server_entities, server_size, per_server_scene, &sm, &snsys]()->void
    {
        uint32_t scene_config_id0 = 0;
        uint32_t scene_config_id1 = 1;
        GetSceneParam weight_round_robin_scene;
        weight_round_robin_scene.scene_confid_ = scene_config_id0;

        uint32_t player_size = 1000;

        std::unordered_map<entt::entity, entt::entity> player_scene1;
        EnterSceneParam enter_param1;

        EntitySet scene_sets;

        for (uint32_t i = 0; i < player_size; ++i)
        {
            auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
            auto p_e = tls.registry.create();
            enter_param1.enterer_ = p_e;
            enter_param1.scene_ = can_enter;
            player_scene1.emplace(enter_param1.enterer_, can_enter);
            scene_sets.emplace(can_enter);
            sm.EnterScene(enter_param1);
        }

        uint32_t player_scene_id = 0;
        for (auto& it : player_scene1)
        {
            auto& pse = tls.registry.get<SceneEntity>(it.first);
            EXPECT_TRUE(pse.scene_entity_ == it.second);
            EXPECT_EQ(tls.registry.get<SceneInfo>(pse.scene_entity_).scene_confid(), scene_config_id0);
        }

        std::unordered_map<entt::entity, entt::entity> player_scene2;
        weight_round_robin_scene.scene_confid_ = scene_config_id1;
        for (uint32_t i = 0; i < player_size; ++i)
        {
            auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
            auto p_e = tls.registry.create();
            enter_param1.enterer_ = p_e;
            enter_param1.scene_ = can_enter;
            player_scene2.emplace(enter_param1.enterer_, enter_param1.scene_);
            scene_sets.emplace(can_enter);
            sm.EnterScene(enter_param1);
        }
        player_scene_id = 0;
        for (auto& it : player_scene2)
        {
            auto& pse = tls.registry.get<SceneEntity>(it.first);
            EXPECT_TRUE(pse.scene_entity_ == it.second);
            EXPECT_EQ(tls.registry.get<SceneInfo>(pse.scene_entity_).scene_confid(), scene_config_id1);
        }

        std::size_t server_player_size = player_size * 2 / server_size;


        for (auto& it : server_entities)
        {
            auto& ps = tls.registry.get<GsNodePlayerInfoPtr>(it);
            EXPECT_EQ((*ps).player_size(), server_player_size);
        }
        EXPECT_EQ(scene_sets.size(), std::size_t(2 * per_server_scene));

        LeaveSceneParam leave_scene;
        for (auto& it : player_scene1)
        {
            auto& pse = tls.registry.get<SceneEntity>(it.first);
            leave_scene.leaver_ = it.first;
            sm.LeaveScene(leave_scene);
        }
        for (auto& it : player_scene2)
        {
            auto& pse = tls.registry.get<SceneEntity>(it.first);
            leave_scene.leaver_ = it.first;
            sm.LeaveScene(leave_scene);
        }
        for (auto& it : server_entities)
        {
            auto& ps = tls.registry.get<GsNodePlayerInfoPtr>(it);
            EXPECT_EQ((*ps).player_size(), 0);
        }
        for (auto& it : player_scene1)
        {
            EXPECT_EQ(tls.registry.get<ScenePlayers>(it.second).size(), 0);
        }
        for (auto& it : player_scene2)
        {
            EXPECT_EQ(tls.registry.get<ScenePlayers>(it.second).size(), 0);
        }
    };
    for (uint32_t i = 0; i < 2; ++i)
    {
        enter_leave_lambda();
    }    
    //leave 
}

TEST(GS, ServerEnterLeavePressure)
{
    tls.registry.clear();
    ScenesSystem sm;
    ServerNodeSystem snsys;
    EntitySet server_entities;
    uint32_t server_size = 2;
    uint32_t per_server_scene = 10;

    for (uint32_t i = 0; i < server_size; ++i)
    {
        server_entities.emplace(CreateMainSceneNode());
    }

    CreateGsSceneP create_server_scene_param;

    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        create_server_scene_param.scene_confid_ = i;
        for (auto& it : server_entities)
        {
            create_server_scene_param.node_ = it;
            sm.CreateScene2Gs(create_server_scene_param);
        }
    }
    ServerPressureParam pressure1;
    pressure1.server_ = *server_entities.begin();
    snsys.ServerEnterPressure( pressure1);
    

    uint32_t scene_config_id0 = 0;
    uint32_t scene_config_id1 = 1;

    GetSceneParam weight_round_robin_scene;
    weight_round_robin_scene.scene_confid_ = scene_config_id0;

    std::unordered_map<entt::entity, entt::entity> player_scene1;

    EnterSceneParam enter_param1;

    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
        auto p_e = tls.registry.create();
        enter_param1.enterer_ = p_e;
        enter_param1.scene_ = can_enter;
        player_scene1.emplace(enter_param1.enterer_, enter_param1.scene_);
        sm.EnterScene(enter_param1);
    }

    uint32_t player_scene_id = 0;

    snsys.ServerEnterNoPressure( pressure1);

    std::unordered_map<entt::entity, entt::entity> player_scene2;
    weight_round_robin_scene.scene_confid_ = scene_config_id1;
    for (uint32_t i = 0; i < per_server_scene; ++i)
    {
        auto can_enter = snsys.GetWeightRoundRobinMainScene(weight_round_robin_scene);
        auto p_e = tls.registry.create();
        enter_param1.enterer_ = p_e;
        enter_param1.scene_ = can_enter;
        player_scene2.emplace(enter_param1.enterer_, enter_param1.scene_);
        sm.EnterScene(enter_param1);
    }

    
}

struct TestNodeId
{
    uint32_t node_id_{ 0 };
};

TEST(GS, GetNotFullMainSceneSceneFull)
{
	tls.registry.clear();
	ScenesSystem sm;
	ServerNodeSystem snsys;
	EntitySet server_entities;
	uint32_t server_size = 10;
	uint32_t per_server_scene = 10;

	for (uint32_t i = 0; i < server_size; ++i)
	{
        auto server = CreateMainSceneNode();
		server_entities.emplace(server);
        tls.registry.emplace<TestNodeId>(server).node_id_ = i;
	}

	CreateGsSceneP create_server_scene_param;

	for (uint32_t i = 0; i < per_server_scene; ++i)
	{
		create_server_scene_param.scene_confid_ = i;
		for (auto& it : server_entities)
		{
			create_server_scene_param.node_ = it;
			auto s1 = sm.CreateScene2Gs(create_server_scene_param);
            tls.registry.emplace<TestNodeId>(s1, tls.registry.get<TestNodeId>(it));
            auto s2 = sm.CreateScene2Gs(create_server_scene_param);
            tls.registry.emplace<TestNodeId>(s2, tls.registry.get<TestNodeId>(it));    
		}
	}

	auto enter_leave_lambda = [&server_entities, server_size, per_server_scene, &sm, &snsys]()->void
	{
		uint32_t scene_config_id0 = 0;
		uint32_t scene_config_id1 = 1;
		GetSceneParam weight_round_robin_scene;
		weight_round_robin_scene.scene_confid_ = scene_config_id0;

		uint32_t player_size = 1001;

		std::unordered_map<entt::entity, entt::entity> player_scene1;
		EnterSceneParam enter_param1;

		EntitySet scene_sets;

		for (uint32_t i = 0; i < player_size; ++i)
		{
			auto can_enter = snsys.GetMainSceneNotFull(weight_round_robin_scene);
            if (can_enter == entt::null)
            {
                continue;
            }
			auto p_e = tls.registry.create();
			enter_param1.enterer_ = p_e;
			enter_param1.scene_ = can_enter;
			player_scene1.emplace(enter_param1.enterer_, can_enter);
			scene_sets.emplace(can_enter);
			sm.EnterScene(enter_param1);
		}

		uint32_t player_scene_id = 0;
		for (auto& it : player_scene1)
		{
			auto& pse = tls.registry.get<SceneEntity>(it.first);
			EXPECT_TRUE(pse.scene_entity_ == it.second);
			EXPECT_EQ(tls.registry.get<SceneInfo>(pse.scene_entity_).scene_confid(), scene_config_id0);
		}

		std::unordered_map<entt::entity, entt::entity> player_scene2;
		weight_round_robin_scene.scene_confid_ = scene_config_id1;
		for (uint32_t i = 0; i < player_size; ++i)
		{
			auto can_enter = snsys.GetMainSceneNotFull(weight_round_robin_scene);
			auto p_e = tls.registry.create();
			enter_param1.enterer_ = p_e;
			enter_param1.scene_ = can_enter;
			player_scene2.emplace(enter_param1.enterer_, enter_param1.scene_);
			scene_sets.emplace(can_enter);
			sm.EnterScene(enter_param1);
		}
		player_scene_id = 0;
		for (auto& it : player_scene2)
		{
			auto& pse = tls.registry.get<SceneEntity>(it.first);
			EXPECT_TRUE(pse.scene_entity_ == it.second);
			EXPECT_EQ(tls.registry.get<SceneInfo>(pse.scene_entity_).scene_confid(), scene_config_id1);
		}

		std::size_t server_player_size = player_size * 2 / server_size;
        std::size_t remain_server_size = player_size * 2 - kMaxScenePlayerSize * 2;
		for (auto& it : server_entities)
		{
			auto& ps = tls.registry.get<GsNodePlayerInfoPtr>(it);
            if (tls.registry.get<TestNodeId>(it).node_id_ == 9)
            {
                EXPECT_EQ((*ps).player_size(), kMaxServerPlayerSize);
            }
            else if (tls.registry.get<TestNodeId>(it).node_id_ == 8)
            {
                EXPECT_EQ((*ps).player_size(), remain_server_size);
            }
            else
            {
                EXPECT_EQ((*ps).player_size(), 0);
            }
		}
		EXPECT_EQ(scene_sets.size(), std::size_t(4));

		LeaveSceneParam leave_scene;
		for (auto& it : player_scene1)
		{
			auto& pse = tls.registry.get<SceneEntity>(it.first);
			leave_scene.leaver_ = it.first;
			sm.LeaveScene(leave_scene);
		}
		for (auto& it : player_scene2)
		{
			auto& pse = tls.registry.get<SceneEntity>(it.first);
			leave_scene.leaver_ = it.first;
			sm.LeaveScene(leave_scene);
		}
		for (auto& it : server_entities)
		{
			auto& ps = tls.registry.get<GsNodePlayerInfoPtr>(it);
			EXPECT_EQ((*ps).player_size(), 0);
		}
		for (auto& it : player_scene1)
		{
			EXPECT_EQ(tls.registry.get<ScenePlayers>(it.second).size(), 0);
		}
		for (auto& it : player_scene2)
		{
			EXPECT_EQ(tls.registry.get<ScenePlayers>(it.second).size(), 0);
		}
	};
	for (uint32_t i = 0; i < 2; ++i)
	{
		enter_leave_lambda();
	}
}

TEST(GS, CreateDungeon)
{
}

TEST(GS, Route)
{
    tls.registry.clear();
}

int32_t main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
