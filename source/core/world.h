#pragma once
#include <core/includes.h>
#include <core/singleton.h>
#include <core/entity.h>
#include <core/light_system.h>

namespace captain_lite
{
	class World : public Singleton<World>, public list<Entity*>
	{
	public:
		World();
		virtual ~World() = default;

		void pushEntity(Entity* entity);

		cpSpace* getSpace();
		LightSystem* getLightSystem();

		void update();
		void draw();

	private:
		cpSpace* space;
		LightSystem light_system;
	};
}