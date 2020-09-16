#include "component_draw.h"

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
	//light.SetRadius(300);
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
	LightSystem::getInstance()->draw(light);
	object->drawSprite();
}