#pragma once
#include <core/components/component.h>
#include <core/world/entity.h>

namespace captain_lite
{
	class ComponentDraw : public IComponent<Entity>
	{
	public:
		ComponentDraw();
		~ComponentDraw();

		void update();
		void draw();
		void onInit();
	};
}