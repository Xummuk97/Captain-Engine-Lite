#include "animation.h"
#include <core/core.h>

Frames::Frames(float delay)
	: _delay(delay)
	, _currentFrame(0)
	, _time(0.0f)
	, _isFlip(false)
	, _isStart(false)
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

void Frames::Start()
{
	_isStart = true;
}

void Frames::Stop()
{
	_isStart = false;
	_time = 0.0f;
	_currentFrame = 0;
}

void Frames::Flip()
{
	if (_isFlip)
	{
		_isFlip = false;
	}
	else
	{
		_isFlip = true;
	}
}

bool Frames::IsStart() const
{
	return _isStart;
}

bool Frames::IsFlip() const
{
	return _isFlip;
}

bool Frames::IsChangeFrame() const
{
	return _isChangeFrame;
}

void Frames::Update()
{
	if (!_isStart)
	{
		return;
	}

	if (_isChangeFrame)
	{
		_isChangeFrame = false;
	}

	_time += Core::deltaTimeInstance;

	if (_time > _delay)
	{
		_time = 0.0f;

		_currentFrame++;
		_isChangeFrame = true;

		if (_currentFrame >= _frames.size())
		{
			_currentFrame = 0;
		}
	}
}
