#pragma once
#include <core/includes.h>
#include <core/components/component.h>
#include <core/world/entity.h>

namespace captain_lite
{
	class ComponentPhysix : public IComponent<Entity>
	{
	public:
		ComponentPhysix();
		~ComponentPhysix();

		void update();
		void draw();
		void onInit();

	private:
		void collisionX(bool dir);
		void collisionY(bool jump);

		void collisionBonus();
	};
}