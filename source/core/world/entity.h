#pragma once
#include <core/includes.h>
#include <core/components/component.h>
#include <core/events.h>

namespace captain_lite
{
	class Entity : public sf::Sprite, public Components<Entity>, public Events<Entity>, public Properties
	{
	public:
		Entity(const string& texture_name, int x, int y, int width, int height);
		virtual ~Entity() = default;

		sf::Vector2f getOriginPosition();

		void update();
		void draw();
		void drawSprite();
	};
}