#include "animation.h"

AnimationManager::AnimationManager(sf::Sprite& sprite)
	: _nameCurrentFrames("")
	, _sprite(sprite)
{
}

Frames& AnimationManager::Add(const string& name, float delay)
{
	auto frames = make_shared<Frames>(name, _sprite, delay);

	_frames[name] = frames;
	frames.reset();

	return *_frames[name];
}

bool AnimationManager::Has(const string& name)
{
	return _frames.find(name) != _frames.end();
}

void AnimationManager::SetNameCurrentFrames(const string& name)
{
	if (_nameCurrentFrames != "")
	{
		GetCurrentFrames().Stop();
	}

	_nameCurrentFrames = name;
	GetCurrentFrames().Start();
}

string AnimationManager::GetNameCurrentFrames() const
{
	return _nameCurrentFrames;
}

Frames& AnimationManager::GetCurrentFrames()
{
	return *_frames[_nameCurrentFrames];
}

void AnimationManager::FlipCurrentFrames()
{
	GetCurrentFrames().Flip();
}
