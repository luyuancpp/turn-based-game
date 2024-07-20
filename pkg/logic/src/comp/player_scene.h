#pragma once

#include "entt/src/entt/entity/entity.hpp"

#include <boost/circular_buffer.hpp>

#include "proto/logic/component//scene_comp.pb.h"

static const uint8_t  kMaxChangeSceneQueue = 3;

struct PlayerCentreChangeSceneQueue
{
	boost::circular_buffer<CentreChangeSceneInfo> change_scene_queue_{ kMaxChangeSceneQueue };
};