#include "timer.h"

void TimerManager::Add(const string& name, shared_ptr<Timer>& timer)
{
	_timers[name] = timer;
	timer.reset();
}

void TimerManager::Update()
{
	for (auto it = _timers.begin(); it != _timers.end();)
	{
		it->second->Update();

		if (it->second->GetFlags() & TIMER_KILL)
		{
			it = _timers.erase(it);
		}
		else
		{
			it++;
		}
	}
}