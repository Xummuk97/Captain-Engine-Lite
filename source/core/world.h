#pragma once
#include <core/includes.h>
#include <core/singleton.h>
#include <core/layer.h>
#include <core/light_system.h>

namespace captain_lite
{
	class World : public Singleton<World>, public list<ILayer*>
	{
	public:
		World();
		virtual ~World() = default;

		void pushLayer(ILayer* layer);

		cpSpace* getSpace();
		LightSystem* getLightSystem();

		void update();
		void draw();

	private:
		cpSpace* space;
		LightSystem light_system;
	};
}