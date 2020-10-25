#include "resource.h"
#include <core/macros.h>

MusicResource::MusicResource(const string& path)
{
	_data = make_unique<sf::Music>();
	_data->openFromFile(PATH_MUSIC + path);
}