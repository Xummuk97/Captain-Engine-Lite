#include "world.h"
#include <core/window.h>

using namespace captain_lite;

World::World()
	: Singleton(this)
{
	space = cpSpaceNew();
	cpSpaceSetIterations(space, 30);
	cpSpaceSetGravity(space, cpv(0, 9.8f));
	cpSpaceSetSleepTimeThreshold(space, 0.5f);
}

void captain_lite::World::pushLayer(ILayer* layer)
{
	push_back(layer);
}

cpSpace* World::getSpace()
{
	return space;
}

LightSystem* captain_lite::World::getLightSystem()
{
	return &light_system;
}

void World::update()
{
	cpSpaceStep(World::getInstance()->getSpace(), Window::getInstance()->getDeltaTime());

	for (ILayer* entity : *this)
	{
		entity->update();
	}
}

void World::draw()
{
	for (ILayer* entity : *this)
	{
		entity->draw();
	}

	light_system.draw();
}
