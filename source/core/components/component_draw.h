#pragma once
#include <core/components/component.h>
#include <core/world/entity.h>
#include <core/world/light_system.h>

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