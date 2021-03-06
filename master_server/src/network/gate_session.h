#pragma once

#include <unordered_map>

#include "src/common_type/common_type.h"
#include "src/game_logic/game_registry.h"

using GateSessionList = std::unordered_map<uint64_t, EntityPtr>;

extern GateSessionList g_gate_sessions;