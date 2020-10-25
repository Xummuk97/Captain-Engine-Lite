#include "resource.h"

#include <core/macros.h>

void ResourceManager::SetTexture(const string& name, const string& path)
{
	auto texture = make_shared<sf::Texture>();
	texture->loadFromFile(PATH_TEXTURES + path);

	_dataTexture[name] = texture;
}

void ResourceManager::SetSound(const string& name, const string& path)
{
	sf::SoundBuffer soundBuffer;
	soundBuffer.loadFromFile(PATH_SOUNDS + path);

	auto sound = make_shared<sf::Sound>();
	sound->setBuffer(soundBuffer);
	
	_dataSounds[name] = sound;
}

void ResourceManager::SetMusic(const string& name, const string& path)
{
	auto music = make_shared<sf::Music>();
	music->openFromFile(PATH_MUSIC + path);

	_dataMusic[name] = music;
}

shared_ptr<sf::Texture> ResourceManager::GetTexture(const string& name)
{
	return _dataTexture[name];
}

shared_ptr<sf::Sound> ResourceManager::GetSound(const string& name)
{
	return _dataSounds[name];
}

shared_ptr<sf::Music> ResourceManager::GetMusic(const string& name)
{
	return _dataMusic[name];
}
