#include "timer.h"
#include <core/core.h>

Timer::Timer(float delay, Func onExpired, int flags)
	: _delay(delay)
	, _onExpired(onExpired)
	, _flags(flags)
	, _time(0.0f)
	, _count(0)
{
}

int Timer::GetFlags() const
{
	return _flags;
}

unsigned int Timer::GetCount() const
{
	return _count;
}

void Timer::Remove()
{
	_flags |= TIMER_KILL;
}

void Timer::Update()
{
	_time += Core::deltaTimeInstance;

	if (_time > _delay)
	{
		_time = 0.0f;
		_count++;
		_onExpired(this);

		if (!(_flags & TIMER_REPEAT))
		{
			Remove();
		}
	}
}
