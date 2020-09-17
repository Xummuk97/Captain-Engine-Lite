#pragma once
#include <core/includes.h>
#include <core/world/entity.h>

namespace captain_lite
{
	class Camera : public Singleton<Camera>
	{
	public:
		Camera();
		Camera(float x, float y, float width, float height);
		Camera(float x, float y, float width, float height, Entity* entity);
		~Camera();

		void bindEntity(Entity* entity);
		sf::FloatRect getVisibleRect();
		bool isVisible(Entity* entity);
		bool isVisible(const sf::FloatRect& rect);
		void reset(float x, float y, float width, float height);

		void update();

	private:
		sf::View view;
		sf::FloatRect visible_rect;
		Entity* entity = nullptr;
	};
}