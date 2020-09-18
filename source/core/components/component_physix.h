#pragma once
#include <core/includes.h>
#include <core/components/component.h>
#include <core/world/entity.h>

namespace captain_lite
{
	const string COMPONENT_PHYSIX_PROP_DIR = "COMPONENT_PHYSIX_PROP_DIR";
	const sf::Vector2f COMPONENT_PHYSIX_GRAVITY_VEC = { 0.0f, 9.8f };

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
	};
}