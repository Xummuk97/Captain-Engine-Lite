#include <core/components/component_draw.h>
#include <core/world/light_system.h>
#include <core/window.h>

using namespace captain_lite;

ComponentDraw::ComponentDraw()
{
}

ComponentDraw::~ComponentDraw()
{
}

void ComponentDraw::update()
{
}

void ComponentDraw::draw()
{
	object->drawSprite();
}

ComponentBackLight::ComponentBackLight()
{
	light.SetRadius(300);
}

ComponentBackLight::~ComponentBackLight()
{

}

void ComponentBackLight::update()
{
	light.SetPosition(object->getOriginPosition());
	LightSystem::getInstance()->update(light);
}

void ComponentBackLight::draw()
{
	Window::getInstance()->draw(light);
	object->drawSprite();
}