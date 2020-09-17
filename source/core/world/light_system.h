#pragma once
#include <core/includes.h>

namespace captain_lite
{
	class LightSystem : public Singleton<LightSystem>
	{
	public:
		LightSystem();
		~LightSystem() = default;

		void add(const sfl::Object& object);

		void update(sfl::Light& light);

		void draw(sfl::Light& light);
		void draw();

	private:
		sfl::LightScene light_scene;
	};
}