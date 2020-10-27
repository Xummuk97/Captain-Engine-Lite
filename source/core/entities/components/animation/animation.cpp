#include "animation.h"

void AnimationComponent::Load(Entity& object)
{
}

void AnimationComponent::Update(Entity& object)
{
	Frames& currentFrame = GetCurrentFrames();
	currentFrame.Update();

	if (currentFrame.IsStart() && currentFrame.IsChangeFrame())
	{
		object.GetSprite().setTextureRect(currentFrame.GetRectCurrentFrame());
	}
}

void AnimationComponent::Draw(Entity& object)
{
}

void AnimationComponent::AddFrame(const string& name, shared_ptr<Frames>& frames)
{
	_frames[name] = frames;
	frames.reset();
}

void AnimationComponent::SetCurrentFrames(const string& name)
{
	if (_currentFrames != "")
	{
		GetCurrentFrames().Stop();
	}

	_currentFrames = name;
	GetCurrentFrames().Start();
}

Frames& AnimationComponent::GetCurrentFrames()
{
	return *_frames[_currentFrames];
}
