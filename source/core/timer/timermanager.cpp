#include "timer.h"

void TimerManager::Add(shared_ptr<Timer>& timer)
{
	_timers.push_back(timer);
	timer.reset();
}

void TimerManager::Update()
{
	for (auto it = _timers.begin(); it != _timers.end();)
	{
		(*it)->Update();

		if ((*it)->GetFlags() & TIMER_KILL)
		{
			it = _timers.erase(it);
		}
		else
		{
			it++;
		}
	}
}