#pragma once
#include <core/includes.h>
#include <core/components/component.h>

namespace captain_lite
{
	class Entity : public Components<Entity>, public Events<Entity>, public Properties
	{
	public:
		Entity(const string& name, const string& texture_name, int x, int y, int width, int height);
		~Entity();

		void setPosition(float x, float y);
		void move(float x, float y);
		sf::Vector2f getOriginPosition();
		sf::FloatRect getGlobalBounds();
		string getName();

		void setKillEnabled(bool enabled);
		bool isKill();

		void update();
		void draw();
		void drawSprite();

	private:
		sf::Sprite sprite;
		string name;
		bool is_kill = false;
	};

	struct EntityInfo : public Properties
	{
		sf::FloatRect rect;

		EntityInfo(const sf::FloatRect& rect);
		~EntityInfo();
	};
}