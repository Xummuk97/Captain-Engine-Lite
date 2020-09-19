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

LayerEntities::LayerEntities(const string& name)
	: ILayer(name)
{
}

LayerEntities::~LayerEntities()
{
	for (Entity* entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

void LayerEntities::pushEntity(Entity* entity)
{
	entities.push_back(entity);
}

Entity* LayerEntities::getEntityFromName(const string& name)
{
	for (Entity* entity : entities)
	{
		if (entity->getName() == name)
		{
			return entity;
		}
	}
	return nullptr;
}

void LayerEntities::getEntitiesFromName(const string& name, list<Entity*>* entities_from_name)
{
	for (Entity* entity : entities)
	{
		if (entity->getName() == name)
		{
			entities_from_name->push_back(entity);
		}
	}
}

void LayerEntities::update()
{
	for (Entity* entity : entities)
	{
		entity->update();
	}
}

void LayerEntities::draw()
{
	for (Entity* entity : entities)
	{
		entity->draw();
	}
}

LayerType LayerEntities::getType()
{
	return LayerType::Objects;
}

Chunk::Chunk()
{
}

Chunk::~Chunk()
{
}

void Chunk::setRect(float x, float y, float width, float height)
{
	rect_chunk = { x, y, width, height };
}

sf::FloatRect Chunk::getRect()
{
	return rect_chunk;
}

void Chunk::pushSprite(const sf::Sprite& sprite)
{
	sprites.push_back(sprite);
}

void Chunk::draw()
{
	sf::FloatRect visible_rect = Camera::getInstance()->getVisibleRect();

	if (visible_rect.intersects(rect_chunk))
	{
		for (sf::Sprite sprite : sprites)
		{
			sf::FloatRect rect_sprite = sprite.getGlobalBounds();

			if (visible_rect.intersects(rect_sprite))
			{
				Window::getInstance()->draw(sprite);
			}
			else
			{
				if ((rect_sprite.left > visible_rect.left + visible_rect.width) &&
					(rect_sprite.top > visible_rect.top + visible_rect.height))
				{
					return;
				}
			}
		}
	}
}

LayerChunks::LayerChunks(const string& name)
	: ILayer(name)
{
}

LayerChunks::~LayerChunks()
{
}

void LayerChunks::pushChunk(Chunk* chunk)
{
	chunks.push_back(chunk);
}

void LayerChunks::update()
{
}

void LayerChunks::draw()
{
	for (Chunk* chunk : chunks)
	{
		chunk->draw();
	}
}

LayerType LayerChunks::getType()
{
	return LayerType::Chunks;
}
