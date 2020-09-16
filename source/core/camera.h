#pragma once
#include <core/includes.h>
#include <core/singleton.h>
#include <core/entity.h>

namespace captain_lite
{
	class Camera : public Singleton<Camera>
	{
	public:
		Camera(float x, float y, float width, float height);
		virtual ~Camera() = default;

		void bind(Entity* entity);
		void update();
		sf::FloatRect getVisibleRect();
		bool isVisible(Entity* entity);

	private:
		sf::View view;
		sf::FloatRect visible_rect;
		Entity* entity;
	};
}