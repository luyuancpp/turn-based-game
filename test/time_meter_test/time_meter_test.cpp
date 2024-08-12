#include <iostream>
#include <chrono>
#include <thread> // 为了演示，引入线程库来模拟时间流逝
#include <gtest/gtest.h>

#include "time/comp/time_meter_util.h"

TEST(TimeMeterUtil, IsExpired)
{
	TimeMeterUtil timeMeter;
	timeMeter.SetDuration(5); // 设置时间测量器持续时间为5秒

	// 开始计时
	timeMeter.Reset();

	// 模拟一些耗时的操作，持续时间不超过5秒
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时1秒的操作
		std::cout << "Time remaining: " << timeMeter.Remaining() << " seconds\n";
		if (timeMeter.IsExpired()) {
			std::cout << "TimeMeter expired!\n";
			break;
		}
	}

	// 调整时间测量器的持续时间为10秒
	timeMeter.SetDuration(10);

	// 重新开始计时
	timeMeter.Reset();

	// 再次模拟一些耗时的操作，持续时间不超过10秒
	for (int i = 0; i < 20; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时1秒的操作
		std::cout << "Time remaining: " << timeMeter.Remaining() << " seconds\n";
		if (timeMeter.IsExpired()) {
			std::cout << "TimeMeter expired!\n";
			break;
		}
	}
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

