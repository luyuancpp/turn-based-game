﻿// test_aoi_system.cpp

#include <gtest/gtest.h>
#include "system/scene/aoi.h"
#include "comp/scene.h"
#include "comp/scene/grid.h"
#include "proto/logic/component/actor_comp.pb.h"
#include "proto/logic/component/npc_comp.pb.h"
#include "proto/logic/event/scene_event.pb.h"
#include "muduo/base/Logging.h"
#include "system/network/message_system.h"
#include "service/scene_client_player_service.h"
#include "hexagons_grid.h"
#include "thread_local/storage.h"
#include "type_alias/actor.h"
#include "util/random.h"

extern const Point kDefaultSize(20.0, 20.0);
extern const Point kOrigin(0.0, 0.0);
extern const auto KFlat = Layout(layout_flat, kDefaultSize, kOrigin);

// Mock class for testing purposes
class MockAoiSystem : public AoiSystem {
public:
    using AoiSystem::GetGridId;
    using AoiSystem::ScanNeighborGridId;
    using AoiSystem::Update;
    using AoiSystem::BeforeLeaveSceneHandler;
    using AoiSystem::UpdateLogGridSize;
    using AoiSystem::LeaveGrid;
};

// Test fixture for AoiSystem
class AoiSystemTest : public ::testing::Test {
protected:
    MockAoiSystem aoi_system;

    void SetUp() override {
        tls.globalRegistry.emplace<ActorCreateS2C>(global_entity());
        tls.globalRegistry.emplace<ActorDestroyS2C>(global_entity());
    }

    void TearDown() override {
        tls.globalRegistry.remove<ActorCreateS2C>(global_entity());
        tls.globalRegistry.remove<ActorDestroyS2C>(global_entity());
        tls.sceneRegistry.clear();
        tls.registry.clear();
    }
};

// Test GetGridId for Location
TEST_F(AoiSystemTest, TestGetGridIdForLocation) {
    Location loc;
    loc.set_x(10);
    loc.set_y(20);
    auto grid_id = aoi_system.GetGridId(loc);

    // Expected value should be calculated based on your logic
    absl::uint128 expected_grid_id = aoi_system.GetGridId(hex_round(pixel_to_hex(KFlat, Point(10, 20))));
    EXPECT_EQ(grid_id, expected_grid_id);
}

// Test ScanNeighborGridId
TEST_F(AoiSystemTest, TestScanNeighborGridId) {
    Hex hex{ 0, 0, 0 };
    GridSet grid_set;
    aoi_system.ScanNeighborGridId(hex, grid_set);

    // Check the number of neighbors
    EXPECT_EQ(grid_set.size(), 6);

    // Check if specific neighbors are present
    for (int i = 0; i < 6; ++i) {
        EXPECT_NE(grid_set.find(aoi_system.GetGridId(hex_neighbor(hex, i))), grid_set.end());
    }
}

// Test Update method for player movement
TEST_F(AoiSystemTest, TestUpdatePlayerMovement) {
    // Mock data setup
    auto sceneEntity = tls.sceneRegistry.create();
    auto& sceneGridList = tls.sceneRegistry.emplace<SceneGridList>(sceneEntity);

    SceneEntityComp sceneEntityComp{ sceneEntity };

    std::unordered_map<absl::uint128, uint32_t, absl::Hash<absl::uint128>> expectedEntityCount;

    for (uint32_t i = 0; i < 10; ++i) {
        auto playerEntity = tls.registry.create();

        Transform& transform = tls.registry.emplace<Transform>(playerEntity);
        transform.mutable_location()->set_x(tls_rand.RandDouble(0, 1000));
        transform.mutable_location()->set_y(tls_rand.RandDouble(0, 1000));

        tls.registry.emplace<SceneEntityComp>(playerEntity, sceneEntityComp);

        // Invoke Update method
        aoi_system.Update(0.1);

        auto grid_id = aoi_system.GetGridId(transform.location());
        ++expectedEntityCount[grid_id];
        EXPECT_TRUE(sceneGridList[grid_id].entity_list.contains(playerEntity));
        EXPECT_EQ(sceneGridList[grid_id].entity_list.size(), expectedEntityCount[grid_id]);
    }

    for (auto&& [scene, grid_list] : tls.sceneRegistry.view<SceneGridList>().each()) {
        for (const auto& [_, entity_list] : grid_list) {
            EXPECT_FALSE(entity_list.entity_list.empty());
        }
    }

    aoi_system.UpdateLogGridSize(0.1);
}

// Test player movement across six neighboring hexes
TEST_F(AoiSystemTest, TestPlayerMovementAcrossSixHexes) {
    // Mock data setup
    auto sceneEntity = tls.sceneRegistry.create();
    auto& sceneGridList = tls.sceneRegistry.emplace<SceneGridList>(sceneEntity);

    auto playerEntity = tls.registry.create();

    Transform& transform = tls.registry.emplace<Transform>(playerEntity);
    transform.mutable_location()->set_x(0);
    transform.mutable_location()->set_y(0);

    SceneEntityComp sceneEntityComp{ sceneEntity };
    tls.registry.emplace<SceneEntityComp>(playerEntity, sceneEntityComp);

    // Initial position
    aoi_system.Update(0.1);
    Hex initialHex = hex_round(pixel_to_hex(KFlat, Point(0, 0)));
    auto initialGridId = aoi_system.GetGridId(initialHex);
    EXPECT_TRUE(sceneGridList[initialGridId].entity_list.contains(playerEntity));

    // Move the player to each neighboring hex
    for (int i = 0; i < 6; ++i) {
        Hex neighborHex = hex_neighbor(initialHex, i);
        Point neighborPoint = hex_to_pixel(KFlat, neighborHex);
        transform.mutable_location()->set_x(neighborPoint.x);
        transform.mutable_location()->set_y(neighborPoint.y);

        // Update the system
        aoi_system.Update(0.1);

        auto newGridId = aoi_system.GetGridId(neighborHex);
        EXPECT_TRUE(sceneGridList[newGridId].entity_list.contains(playerEntity));
        EXPECT_FALSE(sceneGridList[initialGridId].entity_list.contains(playerEntity));

        // Move back to initial hex for next iteration
        transform.mutable_location()->set_x(0);
        transform.mutable_location()->set_y(0);
        aoi_system.Update(0.1);
        EXPECT_TRUE(sceneGridList[initialGridId].entity_list.contains(playerEntity));
        EXPECT_FALSE(sceneGridList[newGridId].entity_list.contains(playerEntity));
    }

    std::size_t expectedSize = 0;
    for (auto&& [scene, grid_list] : tls.sceneRegistry.view<SceneGridList>().each()) {
        for (const auto& [_, entity_list] : grid_list) {
            if (entity_list.entity_list.empty())
            {
                continue;
            }
            EXPECT_EQ(entity_list.entity_list.size(), 1);
            expectedSize += entity_list.entity_list.size();
        }
    }

    EXPECT_EQ(expectedSize, 1);
}

// Add more tests as needed

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
