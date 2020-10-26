#include "animation.h"
#include <core/core.h>

#define PREFIX "timer_"

Frames::Frames(const string& name, sf::Sprite& sprite, float delay)
	: _delay(delay)
	, _sprite(sprite)
	, _name(name)
	, _flags(0)
	, _frameCount(0)
{
}

void Frames::AddFrame(const sf::IntRect& rect)
{
	_data.push_back(rect);
}

int Frames::GetFlags() const
{
	return _flags;
}

void Frames::Start()
{
	if (_flags & FRAMES_STOP)
	{
		_flags ^= FRAMES_STOP;
	}

	auto timer = make_shared<Timer>(_delay, [this](Timer& timer)
	{
		_sprite.setTextureRect(_data[_frameCount]);

		_frameCount++;

		if (_frameCount >= _data.size())
		{
			_frameCount = 0;
		}
	}, TIMER_REPEAT);
	Core::timerManagerInstance.Add(PREFIX + _name, timer);
}

void Frames::Stop()
{
	_flags |= FRAMES_STOP;
	Core::timerManagerInstance.Remove(PREFIX + _name);
}

void Frames::Flip()
{
	if (_flags & FRAMES_FLIP)
	{
		_flags ^= FRAMES_FLIP;
	}
	else
	{
		_flags &= FRAMES_FLIP;
	}
}
