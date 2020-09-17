#include <core/world/light_system.h>
#include <core/window.h>

using namespace captain_lite;

LightSystem::LightSystem()
	: Singleton(this)
{
}

LightSystem::~LightSystem()
{
}

void LightSystem::add(const sfl::Object& object)
{
	light_scene.Add(object);
}

void LightSystem::update(sfl::Light& light)
{
	light_scene.Update(light);
}

void LightSystem::draw()
{
	Window::getInstance()->draw(light_scene);
}
