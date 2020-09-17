#include <core/world/layer.h>
#include <core/window.h>

using namespace captain_lite;

ILayer::ILayer(const string& name)
	: name(name)
{
}

ILayer::~ILayer()
{
}

string ILayer::getName()
{
	return name;
}

LayerObjects::LayerObjects(const string& name)
	: ILayer(name)
{
}

LayerObjects::~LayerObjects()
{
}

void LayerObjects::pushEntity(Entity* entity)
{
	push_back(entity);
}

void LayerObjects::update()
{
	for (Entity* entity : *this)
	{
		entity->update();
	}
}

void LayerObjects::draw()
{
	for (Entity* entity : *this)
	{
		entity->draw();
	}
}

LayerType LayerObjects::getType()
{
	return LayerType::Objects;
}

LayerChunks::LayerChunks(const string& name)
	: ILayer(name)
{
}

LayerChunks::~LayerChunks()
{
}

void LayerChunks::pushSprite(const sf::Sprite& sprite)
{
	push_back(sprite);
}

void LayerChunks::update()
{
}

void LayerChunks::draw()
{
	for (sf::Sprite sprite : *this)
	{
		Window::getInstance()->getRenderWindow()->draw(sprite);
	}
}

LayerType LayerChunks::getType()
{
	return LayerType::Chunks;
}