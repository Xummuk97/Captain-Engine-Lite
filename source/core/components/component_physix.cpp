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
	is_collision_bonus = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		object->move(-100.0f, 0.0f);
		collisionX(true);
		collisionBonus();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		object->move(100.0f, 0.0f);
		collisionX(false);
		collisionBonus();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		object->move(0.0f, -9.8f);
		collisionY(true);
		collisionBonus();
	}
	else
	{
		object->move(0.0f, 9.8f);
		collisionY(false);
		collisionBonus();
	}
}

void ComponentPhysix::draw()
{
}

void ComponentPhysix::onInit()
{
}

void ComponentPhysix::collisionX(bool dir)
{
	list<EntityInfo*> collision_entities = World::getInstance()->getEntitiesInfo("collision");

	sf::FloatRect object_rect = object->getGlobalBounds();

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
	list<EntityInfo*> collision_entities = World::getInstance()->getEntitiesInfo("collision");

	sf::FloatRect object_rect = object->getGlobalBounds();

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

void ComponentPhysix::collisionBonus()
{
	if (is_collision_bonus)
	{
		return;
	}

	list<Entity*> entitites = World::getInstance()->getEntitiesFromName("bonus");

	sf::FloatRect object_rect = object->getGlobalBounds();

	for (Entity* entity : entitites)
	{
		if (object_rect.intersects(entity->getGlobalBounds()))
		{
			cout << "BONUS COLLISION!" << endl;
			entity->setKillEnabled(true);
			is_collision_bonus = true;
			return;
		}
	}
}
