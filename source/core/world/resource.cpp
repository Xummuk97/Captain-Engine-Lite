#include <core/world/resource.h>

using namespace captain_lite;

IResource::IResource()
{
}

IResource::~IResource()
{
}

ResourceTexture::ResourceTexture(const string& file)
{
	loadFromFile("resources/textures/" + file);
}

ResourceTexture::~ResourceTexture()
{
}

ResourceSound::ResourceSound(const string& file)
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("resources/sounds/" + file);

	setBuffer(buffer);
}

ResourceSound::~ResourceSound()
{
}

Resources::Resources()
	: Singleton(this)
{
}

Resources::~Resources()
{
}

void Resources::add(const string& name, IResource* resource)
{
	resources[name] = resource;
}
