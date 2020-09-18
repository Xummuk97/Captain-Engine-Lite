#include "properties.h"

using namespace captain_lite;

Properties::Properties()
{
}

Properties::~Properties()
{
}

void Properties::setProperty(const string& name, int value)
{
	properties[name].int_value = value;
}

void Properties::setProperty(const string& name, float value)
{
	properties[name].float_value = value;
}

void Properties::setProperty(const string& name, const string& value)
{
	properties[name].string_value = value;
}

void Properties::setProperty(const string& name, const sf::Vector2i& value)
{
	properties[name].vector2i_value = value;
}

void Properties::setProperty(const string& name, const sf::Vector2f& value)
{
	properties[name].vector2f_value = value;
}

void Properties::setProperty(const string& name, const sf::IntRect& value)
{
	properties[name].intrect_value = value;
}

void Properties::setProperty(const string& name, const sf::FloatRect& value)
{
	properties[name].floatrect_value = value;
}

int Properties::getPropertyInt(const string& name)
{
	return properties[name].int_value;
}

float Properties::getPropertyFloat(const string& name)
{
	return properties[name].float_value;
}

string Properties::getPropertyString(const string& name)
{
	return properties[name].string_value;
}

sf::Vector2i Properties::getPropertyVector2i(const string& name)
{
	return properties[name].vector2i_value;
}

sf::Vector2f Properties::getPropertyVector2f(const string& name)
{
	return properties[name].vector2f_value;
}

sf::IntRect Properties::getPropertyIntRect(const string& name)
{
	return properties[name].intrect_value;
}

sf::FloatRect Properties::getPropertyFloatRect(const string& name)
{
	return properties[name].floatrect_value;
}
