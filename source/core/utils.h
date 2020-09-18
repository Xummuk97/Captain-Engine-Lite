#pragma once
#include <SFML/Graphics.hpp>
#include <tinyxml2/tinyxml2.h>

#include <string>

using namespace tinyxml2;
using namespace std;

namespace captain_lite
{
	class Utils
	{
	public:
		static sf::Vector2f getXmlAttributeVector2f(XMLElement* element);
		static sf::FloatRect getXmlAttributeFloatRect(XMLElement* element);

		static void loadTextureFromResources(const string& texture_name, sf::Sprite& sprite, int x, int y, int width, int height);
	};
}