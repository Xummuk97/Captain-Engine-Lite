#include <core/world/light_system.h>
#include <core/window.h>

using namespace captain_lite;

LightSystem::LightSystem()
	: Singleton(this)
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

void LightSystem::draw(sfl::Light& light)
{
	light.Render(*Window::getInstance()->getRenderWindow());
}

void LightSystem::draw()
{
	light_scene.Render(*Window::getInstance()->getRenderWindow());
}
