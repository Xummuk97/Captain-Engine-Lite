#pragma once
#include <core/component.h>
#include <core/entity.h>
#include <core/light_system.h>

namespace captain_lite
{
	class ComponentDraw : public IComponent<Entity>
	{
	public:
		ComponentDraw();
		~ComponentDraw();

		void update();
		void draw();
	};

	class ComponentBackLight : public IComponent<Entity>
	{
	public:
		ComponentBackLight();
		~ComponentBackLight();

		void update();
		void draw();

	private:
		sfl::Light light;
	};
}