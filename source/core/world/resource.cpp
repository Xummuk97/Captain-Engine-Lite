#include <core/world/resource.h>

using namespace captain_lite;

ResourceTexture::ResourceTexture(const string& file)
{
	loadFromFile("resources/textures/" + file);
}

ResourceSound::ResourceSound(const string& file)
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("resources/sounds/" + file);

	setBuffer(buffer);
}

Resources::Resources()
	: Singleton(this)
{
}

void Resources::add(const string& name, IResource* resource)
{
	resources[name] = resource;
}
