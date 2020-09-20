#include "properties.h"

using namespace captain_lite;

Properties::Properties()
{
}

Properties::~Properties()
{
}

void Properties::setProperty(const string& name, char* value)
{
	setProperty(name, string(value));
}

void Properties::setProperty(const string& name, const char* value)
{
	setProperty(name, string(value));
}

void Properties::setProperty(const string& name, any value)
{
	properties[name] = value;
}
