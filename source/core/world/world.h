#pragma once
#include <core/includes.h>
#include <core/world/layer.h>
#include <core/world/light_system.h>

namespace captain_lite
{
	class World : public Singleton<World>, public list<ILayer*>
	{
	public:
		World();
		virtual ~World() = default;

		void loadMap(const string& file);
		void pushLayer(ILayer* layer);

		cpSpace* getSpace();
		LightSystem* getLightSystem();

		void update();
		void draw();

	private:
		void loadMapFromTMX(const string& file);

		cpSpace* space;
		LightSystem light_system;
		sf::Texture texture_map;
		vector<sf::IntRect> image_rects;
	};
}