#include <core/components/component_physix.h>
#include <core/world/world.h>

using namespace captain_lite;

ComponentPhysix::ComponentPhysix()
{
	
}

ComponentPhysix::~ComponentPhysix()
{
}

void ComponentPhysix::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		object->move(-100.0f, 0.0f);
		collisionX(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		object->move(100.0f, 0.0f);
		collisionX(false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		object->move(0.0f, -9.8f);
		collisionY(true);
	}
	else
	{
		object->move(0.0f, 9.8f);
		collisionY(false);
	}
}

void ComponentPhysix::draw()
{
}

void ComponentPhysix::onInit()
{
	object->setProperty(COMPONENT_PHYSIX_PROP_DIR, sf::Vector2f());
}

void ComponentPhysix::collisionX(bool dir)
{
	sf::FloatRect object_rect = object->getGlobalBounds();

	list<EntityInfo*> collision_entities = World::getInstance()->getEntitiesInfo("collision");

	for (EntityInfo* collision_entity : collision_entities)
	{
		sf::FloatRect rect = collision_entity->rect;

		if (rect.intersects(object_rect))
		{
			if (dir)
			{
				object_rect.left = rect.left + rect.width;
			}
			else
			{
				object_rect.left = rect.left - object_rect.width;
			}

			object->setPosition(object_rect.left, object_rect.top);
			return;
		}
	}
}

void ComponentPhysix::collisionY(bool jump)
{
	sf::FloatRect object_rect = object->getGlobalBounds();

	list<EntityInfo*> collision_entities = World::getInstance()->getEntitiesInfo("collision");

	for (EntityInfo* collision_entity : collision_entities)
	{
		sf::FloatRect rect = collision_entity->rect;

		if (rect.intersects(object_rect))
		{
			if (jump)
			{
				object_rect.top = rect.top + rect.height;
			}
			else
			{
				object_rect.top = rect.top - object_rect.height;
			}
			
			object->setPosition(object_rect.left, object_rect.top);
			return;
		}
	}
}
