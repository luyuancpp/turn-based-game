#pragma once

#include <cstdint>

class TimeUtil
{
public:
	static uint64_t NowMilliseconds();

	static uint64_t NowSeconds();

	static uint64_t NowMillisecondsUTC();

	static uint64_t NowSecondsUTC();
};