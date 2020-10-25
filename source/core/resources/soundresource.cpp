#include "resource.h"
#include <core/macros.h>

SoundResource::SoundResource(const string& path)
{
	sf::SoundBuffer soundBuffer;
	soundBuffer.loadFromFile(PATH_SOUNDS + path);

	_data = make_unique<sf::Sound>();
	_data->setBuffer(soundBuffer);
}