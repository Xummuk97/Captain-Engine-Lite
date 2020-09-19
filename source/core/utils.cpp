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

string Utils::toString(int x)
{
    return to_string(x);
}

string Utils::toString(unsigned int x)
{
    return to_string(x);
}

string Utils::toString(long x)
{
    return to_string(x);
}

string Utils::toString(unsigned long x)
{
    return to_string(x);
}

string Utils::toString(long long x)
{
    return to_string(x);
}

string Utils::toString(unsigned long long x)
{
    return to_string(x);
}

string Utils::toString(float x)
{
    return to_string(x);
}

string Utils::toString(double x)
{
    return to_string(x);
}

string Utils::toString(long double x)
{
    return to_string(x);
}

string Utils::toString(const char* x)
{
    return string(x);
}

string Utils::toString(const string& x)
{
    return x;
}

const tm* Utils::getTime()
{
    time_t seconds = time(NULL);
    tm* ti = localtime(&seconds);
    return ti;
}

string Utils::formatTime(const tm* ti, const string& fmt)
{
    char time[128];
    strftime(time, sizeof(time), fmt.c_str(), ti);
    return string(time);
}

string Utils::toString(char* x)
{
    return string(x);
}