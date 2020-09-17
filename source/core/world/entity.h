#pragma once
#include <core/includes.h>
#include <core/components/component.h>
#include <core/events.h>

namespace captain_lite
{
	class Entity : public Components<Entity>, public Events<Entity>, public Properties
	{
	public:
		Entity(const string& texture_name, int x, int y, int width, int height);
		~Entity();

		sf::Vector2f getOriginPosition();
		sf::FloatRect getGlobalBounds();

		void update();
		void draw();
		void drawSprite();

	private:
		sf::Sprite sprite;
	};
}