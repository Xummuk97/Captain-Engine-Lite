#include "animation.h"
#include <core/core.h>

Frames::Frames(float delay)
	: _delay(delay)
	, _currentFrame(0)
	, _time(0.0f)
	, _flags(0)
{
}

void Frames::AddFrame(const sf::IntRect& rect)
{
	_frames.push_back(rect);
}

sf::IntRect Frames::GetRectCurrentFrame() const
{
	return _frames[_currentFrame];
}

void Frames::Run()
{
	_flags |= (FRAMES_RUN | FRAMES_BEGIN);
}

void Frames::Stop()
{
	_flags ^= FRAMES_RUN;
	_time = 0.0f;
	_currentFrame = 0;
}

void Frames::Flip()
{
	if (IsFlip())
	{
		_flags ^= FRAMES_FLIP;
	}
	else
	{
		_flags |= FRAMES_FLIP;
	}
}

bool Frames::IsRun() const
{
	return _flags & FRAMES_RUN;
}

bool Frames::IsFlip() const
{
	return _flags & FRAMES_FLIP;
}

bool Frames::IsChangeFrame() const
{
	return _flags & FRAMES_CHAGE_FRAME;
}

bool Frames::IsBegin() const
{
	return _flags & FRAMES_BEGIN;
}

void Frames::Update()
{
	if (!IsRun())
	{
		return;
	}

	if (IsChangeFrame())
	{
		_flags ^= FRAMES_CHAGE_FRAME;
	}

	if (IsBegin())
	{
		_flags ^= FRAMES_BEGIN;
	}

	_time += Core::deltaTimeInstance;

	if (_time > _delay)
	{
		_time = 0.0f;

		_currentFrame++;
		_flags |= FRAMES_CHAGE_FRAME;

		if (_currentFrame >= _frames.size())
		{
			_currentFrame = 0;
		}
	}
}
