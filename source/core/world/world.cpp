#include <core/world/world.h>
#include <core/world/camera.h>
#include <core/world/background.h>
#include <core/window.h>

using namespace captain_lite;

World::World()
	: Singleton(this)
	, Events(this)
{
}

World::~World()
{
	clear();
}

void World::loadMap(const string& file)
{
	if (file.find(".tmx") != string::npos)
	{
		loadMapFromTMX(file);
	}
}

void World::loadMapFromTMX(const string& file)
{
	XMLDocument doc;
	doc.LoadFile(("resources/levels/" + file).c_str());

	XMLElement* root = doc.FirstChildElement();

	XMLElement* tileset = root->FirstChildElement("tileset");
	tile_width = tileset->IntAttribute("tilewidth");
	tile_height = tileset->IntAttribute("tileheight");

	XMLElement* image = tileset->FirstChildElement("image");
	string texture_file = string("resources/levels/") + image->Attribute("source");
	int trans = image->IntAttribute("trans");

	loadMapTexture(texture_file, trans);

	int image_width = image->IntAttribute("width");
	int image_height = image->IntAttribute("height");

	int image_count_x = image_width / tile_width;
	int image_count_y = image_height / tile_height;

	loadMapTextureRects(image_count_x, image_count_y, image_width, image_height);

	XMLElement* element = root->FirstChildElement("layer");
	string layer_name, element_name;

	while (element)
	{
		layer_name = element->Attribute("name");
		element_name = element->Name();

		if (element_name == "layer")
		{
			loadMapChunksFromTMX(element, layer_name);
		}
		else if (element_name == "objectgroup")
		{
			loadMapEntitiesFromTMX(element, layer_name);
		}

		element = element->NextSiblingElement();
	}
}

void World::loadMapChunksFromTMX(XMLElement* element, const string& layer_name)
{
	LayerChunks* chunks = new LayerChunks(layer_name);

	XMLElement* chunk_element = element->FirstChildElement("data")->FirstChildElement("chunk");
	while (chunk_element)
	{
		Chunk* chunk = new Chunk;

		int chunk_pos_x = chunk_element->IntAttribute("x") * tile_width;
		int chunk_pos_y = chunk_element->IntAttribute("y") * tile_height;
		int chunk_width = chunk_element->IntAttribute("width");
		int chunk_height = chunk_element->IntAttribute("height");

		int element_pos_x = 0;
		int element_pos_y = 0;

		chunk->setRect((float)chunk_pos_x, (float)chunk_pos_y, float(chunk_width * tile_width), float(chunk_height * tile_height));

		string chunk_text = chunk_element->GetText();
		size_t size = chunk_text.size();
		string num;
		for (size_t i = 0; i < size; i++)
		{
			if (chunk_text[i] == ',' || i == (size - 1))
			{
				int tile_id = stoi(num) - 1;

				if (tile_id >= 0)
				{
					sf::Sprite sprite;
					sprite.setTexture(map_texture);
					sprite.setTextureRect(map_rects[tile_id]);
					sprite.setPosition({ float(chunk_pos_x + element_pos_x * tile_width), float(chunk_pos_y + element_pos_y * tile_height) });
					chunk->pushSprite(sprite);
				}

				num.clear();
				element_pos_x++;

				if (element_pos_x >= chunk_width)
				{
					element_pos_x = 0;
					element_pos_y++;
				}
			}
			else
			{
				num.push_back(chunk_text[i]);
			}
		}

		chunks->pushChunk(chunk);
		chunk_element = chunk_element->NextSiblingElement("chunk");
	}

	pushLayer(chunks);
}

void World::loadMapEntitiesFromTMX(XMLElement* element, const string& layer_name)
{
	object_element = element->FirstChildElement("object");
	object_layer_name = layer_name;

	while (object_element)
	{
		callEvent(WORLD_EVENT_LOAD_ENTITY);
		object_element = object_element->NextSiblingElement();
	}
}

void World::loadMapTexture(const string& texture_file, int trans)
{
	sf::Image image_map;
	image_map.loadFromFile(texture_file);
	image_map.createMaskFromColor(sf::Color(trans));
	map_texture.loadFromImage(image_map);
}

void World::loadMapTextureRects(int image_count_x, int image_count_y, int image_width, int image_height)
{
	map_rects.clear();
	sf::IntRect rect;
	for (int y = 0; y < image_count_y; y++)
	{
		for (int x = 0; x < image_count_x; x++)
		{
			rect.left = x * tile_width;
			rect.top = y * tile_height;
			rect.width = tile_width;
			rect.height = tile_height;
			map_rects.push_back(rect);
		}
	}
}

void World::pushLayer(ILayer* layer)
{
	layers.push_back(layer);
}

LayerObjects* World::getEntityLayer(const string& name)
{
	for (ILayer* layer : layers)
	{
		if (layer->getName() == name)
		{
			return (LayerObjects*)layer;
		}
	}

	LayerObjects* layer_objects = new LayerObjects(name);
	pushLayer(layer_objects);
	return layer_objects;
}

void World::clear()
{
	for (ILayer* layer : layers)
	{
		delete layer;
	}
	layers.clear();

	for (pair<string, list<EntityInfo*>> entities_info : group_entities_info)
	{
		for (EntityInfo* entity_info : entities_info.second)
		{
			delete entity_info;
		}
		entities_info.second.clear();
	}
	group_entities_info.clear();
}

void World::pushEntityInfo(const string& name, EntityInfo* entity_info)
{
	group_entities_info[name].push_back(entity_info);
}

EntityInfo* World::getEntityInfo(const string& name)
{
	list<EntityInfo*> entities_info = group_entities_info[name];

	if (entities_info.size() == 0)
	{
		return nullptr;
	}

	return entities_info.front();
}

list<EntityInfo*>& World::getEntitiesInfo(const string& name)
{
	return group_entities_info[name];
}

XMLElement* World::getLastLoadObject()
{
	return object_element;
}

string World::getLastLayerName()
{
	return object_layer_name;
}

void World::update()
{
	for (ILayer* entity : layers)
	{
		entity->update();
	}

	Camera::getInstance()->update();
	Background::getInstance()->update();
}

void World::draw()
{
	Background::getInstance()->draw();

	for (ILayer* entity : layers)
	{
		entity->draw();
	}
}
