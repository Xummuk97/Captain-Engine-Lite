#pragma once
#include <core/includes.h>

#define TIMER_REPEAT (1 << 0)
#define TIMER_KILL (1 << 10)

class Timer
{
	using Func = void(*)(Timer* timer);

	Func _onExpired;
	float _delay;
	float _time;
	int _flags;
	unsigned int _count;

public:
	Timer(float delay, Func onExpired, int flags = 0);
	virtual ~Timer() = default;

	int GetFlags() const;
	unsigned int GetCount() const;
	void Remove();

	void Update();
};

class TimerManager
{
	list<shared_ptr<Timer>> _timers;

public:
	TimerManager() = default;
	virtual ~TimerManager() = default;

	void Add(shared_ptr<Timer>& timer);

	void Update();
};