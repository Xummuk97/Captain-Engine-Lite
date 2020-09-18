#include "component_physix.h"

using namespace captain_lite;

ComponentPhysix::ComponentPhysix()
{
	
}

ComponentPhysix::~ComponentPhysix()
{
}

void ComponentPhysix::update()
{
}

void ComponentPhysix::draw()
{
}

void ComponentPhysix::onInit()
{
	object->setProperty(COMPONENT_PHYSIX_PROP_DIR, sf::Vector2f(24.2f, 13.1f));
}
