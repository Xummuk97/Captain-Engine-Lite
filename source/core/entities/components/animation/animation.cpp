#include "animation.h"
#include <core/macros.h>

void AnimationComponent::Load(Entity& object)
{
}

void AnimationComponent::Update(Entity& object)
{
	Frames& currentFrame = GetCurrentFrames();
	bool isBegin = currentFrame.IsBegin();

	currentFrame.Update();

	if (isBegin || (currentFrame.IsRun() && currentFrame.IsChangeFrame()))
	{
		object.GetSprite().setTextureRect(currentFrame.GetRectCurrentFrame());
	}
}

void AnimationComponent::Draw(Entity& object)
{
}

void AnimationComponent::AddFrames(const string& name, shared_ptr<Frames>& frames)
{
	_frames[name] = frames;
	frames.reset();
}

void AnimationComponent::Run(const string& name)
{
	if (_currentFrames != "")
	{
		GetCurrentFrames().Stop();
	}

	_currentFrames = name;
	GetCurrentFrames().Run();
}

Frames& AnimationComponent::GetCurrentFrames()
{
	return *_frames[_currentFrames];
}

void AnimationComponent::LoadFromFile(const string& path)
{
	XMLDocument doc;
	if (doc.LoadFile((PATH_ANIMATIONS + path).c_str()) != XMLError::XML_SUCCESS)
	{
		return;
	}

	XMLElement* root = doc.RootElement();
	string def = root->Attribute("default");

	XMLElement* frames = root->FirstChildElement("frames");

	while (frames)
	{
		string name = frames->Attribute("name");
		float delay = frames->FloatAttribute("delay");

		shared_ptr<Frames> frameInstance = make_shared<Frames>(delay);

		XMLElement* frame = frames->FirstChildElement("frame");

		while (frame)
		{
			int x = frame->IntAttribute("x");
			int y = frame->IntAttribute("y");
			int width = frame->IntAttribute("width");
			int height = frame->IntAttribute("height");

			frameInstance->AddFrame({ x, y, width, height });

			frame = frame->NextSiblingElement("frame");
		}

		AddFrames(name, frameInstance);

		frames = frames->NextSiblingElement("frames");
	}

	Run(def);
}
