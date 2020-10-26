#include "timer.h"

void TimerManager::Add(const string& name, shared_ptr<Timer>& timer)
{
	_timers[name] = timer;
	timer.reset();
}

bool TimerManager::Has(const string& name)
{
	return _timers.find(name) != _timers.end();
}

void TimerManager::Remove(const string& name)
{
	if (!Has(name))
	{
		throw "[TimerManager::Remove] Error: Timer '" + name + "' not found.";
	}

	_timers.erase(name);
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