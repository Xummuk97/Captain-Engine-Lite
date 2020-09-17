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
