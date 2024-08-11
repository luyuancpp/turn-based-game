#include "timer_task_comp.h"

#include "muduo/net/TimerId.h"
#include "muduo/net/Timer.h"

#define  gs_thread_even_loop EventLoop::getEventLoopOfCurrentThread()

TimerTaskComp::~TimerTaskComp()
{
    Cancel();
}

void TimerTaskComp::RunAt(const Timestamp& time, const TimerCallback& cb)
{
	Cancel();
    callback_ = cb;
	id_ = gs_thread_even_loop->runAt(time, std::bind(&TimerTaskComp::OnTimer, this));
    UpdateEndStamp();
}

void TimerTaskComp::RunAfter(double delay, const TimerCallback& cb)
{
	Cancel();
    callback_ = cb;
    id_ = gs_thread_even_loop->runAfter(delay, std::bind(&TimerTaskComp::OnTimer, this));
    UpdateEndStamp();
}

void TimerTaskComp::RunEvery(double interval, const TimerCallback& cb)
{
    Cancel();	
    callback_ = cb;
    id_ = gs_thread_even_loop->runEvery(interval, std::bind(&TimerTaskComp::OnTimer, this));
    UpdateEndStamp();
}

void TimerTaskComp::Call()
{
    if (!callback_)
    {
        return;
    }
    callback_();
}

void TimerTaskComp::Cancel()
{
    gs_thread_even_loop->cancel(id_);
    id_ = TimerId();
    endTime = Timestamp();
    assert(nullptr == id_.GetTimer());
}

bool TimerTaskComp::IsActive()
{
    return !(endTime.invalid() == endTime);
}

int32_t TimerTaskComp::GetEndTime()
{
    if (endTime < Timestamp::now() )
    {
        return 0;
    }
    return (int32_t)id_.GetTimer()->expiration().secondsSinceEpoch();
}

void TimerTaskComp::UpdateEndStamp()
{
    if (nullptr == id_.GetTimer())
    {
        return;
    }
    endTime = id_.GetTimer()->expiration();
}

void TimerTaskComp::SetCallBack(const TimerCallback& cb)
{
    callback_ = cb;
}

void TimerTaskComp::OnTimer()
{
    if (!callback_)
    {
        return;
    }
    TimerCallback copycb = callback_;
    copycb();
    endTime = Timestamp();
}
