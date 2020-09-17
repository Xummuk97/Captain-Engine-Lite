#pragma once
#include <core/includes.h>
#include <core/components/component.h>

namespace captain_lite
{
	class Entity : public sf::Sprite, public Components<Entity>
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