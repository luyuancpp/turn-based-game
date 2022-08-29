#pragma once

#include <cstdint>

enum eCondtionType : uint32_t
{
	E_CONDITION_KILL_MONSTER = 1,
	E_CONDITION_TALK_WITH_NPC,
	E_CONDITION_COMPLELETE_CONDITION,
	E_CONDITION_USE_ITEM,
	E_CONDITION_INTERATION,
	E_CONDITION_LEVEUP,
	E_CONDITION_COMSTUM,
	E_CONDITION_COMPLELTE_MISSION,
	E_CONDITION_MAX,
};

enum eConditionIndex
{
	E_CONDITION_1,
	E_CONDITION_2
};