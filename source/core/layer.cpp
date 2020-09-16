#include "layer.h"

using namespace captain_lite;

ILayer::ILayer(const string& name)
	: name(name)
{
}

ILayer::~ILayer()
{
}

LayerNormal::LayerNormal(const string& name)
	: ILayer(name)
{
}

LayerNormal::~LayerNormal()
{
}

void LayerNormal::pushEntity(Entity* entity)
{
	push_back(entity);
}

void LayerNormal::update()
{
	for (Entity* entity : *this)
	{
		entity->update();
	}
}

void LayerNormal::draw()
{
	for (Entity* entity : *this)
	{
		entity->draw();
	}
}

LayerType LayerNormal::getType()
{
	return LayerType::Normal;
}
