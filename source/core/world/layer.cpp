#include <core/world/layer.h>
#include <core/world/camera.h>
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
	for (Entity* entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

void LayerObjects::pushEntity(Entity* entity)
{
	entities.push_back(entity);
}

void LayerObjects::update()
{
	for (Entity* entity : entities)
	{
		entity->update();
	}
}

void LayerObjects::draw()
{
	for (Entity* entity : entities)
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
	sprites.push_back(sprite);
}

void LayerChunks::update()
{
}

void LayerChunks::draw()
{
	for (sf::Sprite sprite : sprites)
	{
		if (Camera::getInstance()->isVisible(sprite.getGlobalBounds()))
		{
			Window::getInstance()->draw(sprite);
		}
	}
}

LayerType LayerChunks::getType()
{
	return LayerType::Chunks;
}