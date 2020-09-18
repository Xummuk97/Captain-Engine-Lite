#pragma once
#include <core/includes.h>
#include <core/components/component.h>
#include <core/world/entity.h>

namespace captain_lite
{
	const string COMPONENT_PHYSIX_PROP_DIR = "COMPONENT_PHYSIX_PROP_DIR";

	class ComponentPhysix : public IComponent<Entity>
	{
	public:
		ComponentPhysix();
		~ComponentPhysix();

		void update();
		void draw();
		void onInit();
	};
}