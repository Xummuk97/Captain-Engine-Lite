#include "resource.h"
#include <core/macros.h>

TextureResource::TextureResource(const string& path)
{
	_data = make_unique<sf::Texture>();
	_data->loadFromFile(PATH_TEXTURES + path);
}
