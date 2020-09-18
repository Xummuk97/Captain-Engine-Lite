#pragma once
#include <core/includes.h>
#include <core/world/layer.h>

namespace captain_lite
{
	class World : public Singleton<World>
	{
	public:
		World();
		~World();

		void loadMap(const string& file);
		void pushLayer(ILayer* layer);
		void clear();

		void update();
		void draw();

	private:
		void loadMapFromTMX(const string& file);

		sf::Texture texture_map;
		vector<sf::IntRect> image_rects;
		list<ILayer*> layers;
	};
}