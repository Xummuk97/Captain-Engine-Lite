#pragma once
#include <core/includes.h>
#include <core/world/layer.h>

namespace captain_lite
{
	const string WORLD_EVENT_LOAD_ENTITY = "load_entity";

	class World : public Singleton<World>, public Events<World>
	{
	public:
		World();
		~World();

		void loadMap(const string& file);
		void pushLayer(ILayer* layer);
		LayerObjects* getEntityLayer(const string& name);
		void pushEntityInfo(const string& name, EntityInfo* entity_info);
		EntityInfo* getEntityInfo(const string& name);
		list<EntityInfo*>& getEntitiesInfo(const string& name);
		void clear();

		XMLElement* getLastLoadObject();
		string getLastLayerName();

		void update();
		void draw();

	private:
		void loadMapFromTMX(const string& file);

		void loadMapChunksFromTMX(XMLElement* element, const string& layer_name);
		void loadMapEntitiesFromTMX(XMLElement* element, const string& layer_name);

		void loadMapTexture(const string& texture_file, int trans);
		void loadMapTextureRects(int image_count_x, int image_count_y, int image_width, int image_height);

		sf::Texture map_texture;
		vector<sf::IntRect> map_rects;
		int map_width;
		int map_height;
		int tile_width;
		int tile_height;

		list<ILayer*> layers;
		map<string, list<EntityInfo*>> group_entities_info;
		XMLElement* object_element;
		string object_layer_name;
	};
}