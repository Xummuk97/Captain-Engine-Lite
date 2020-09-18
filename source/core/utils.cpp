#include <core/utils.h>
#include <core/world/resource.h>

using namespace captain_lite;

sf::Vector2f Utils::getXmlAttributeVector2f(XMLElement* element)
{
    float x = element->FloatAttribute("x");
    float y = element->FloatAttribute("y");
    return { x, y };
}

sf::FloatRect Utils::getXmlAttributeFloatRect(XMLElement* element)
{
    float x = element->FloatAttribute("x");
    float y = element->FloatAttribute("y");
    float width = element->FloatAttribute("width");
    float height = element->FloatAttribute("height");
    return { x, y, width, height };
}

void Utils::loadTextureFromResources(const string& texture_name, sf::Sprite& sprite, int x, int y, int width, int height)
{
    sprite.setTexture(Resources::getInstance()->get<ResourceTexture>(texture_name));
    sprite.setTextureRect({ x, y, width, height });
}
