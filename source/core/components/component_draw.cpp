#include <core/components/component_draw.h>
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