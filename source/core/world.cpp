#include "world.h"
#include <core/window.h>

using namespace captain_lite;

World::World()
	: Singleton(this)
{
	space = cpSpaceNew();
	cpSpaceSetIterations(space, 30);
	cpSpaceSetGravity(space, cpv(0, 9.8f));
	cpSpaceSetSleepTimeThreshold(space, 0.5f);
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
	int firstgid = tileset->IntAttribute("firstgid");
	int tilewidth = tileset->IntAttribute("tilewidth");
	int tileheight = tileset->IntAttribute("tileheight");
	int tilecount = tileset->IntAttribute("tilecount");
	int columns = tileset->IntAttribute("columns");

	XMLElement* image = tileset->FirstChildElement("image");
	sf::Image image_map;
	image_map.loadFromFile(string("resources/levels/") + image->Attribute("source"));
	image_map.createMaskFromColor(sf::Color(image->IntAttribute("trans")));
	texture_map.loadFromImage(image_map);

	int imagewidth = tileset->IntAttribute("width");
	int imageheight = tileset->IntAttribute("height");

	int image_count_x = imagewidth / tilewidth;
	int image_count_y = imageheight / tileheight;

	image_rects.clear();
	sf::IntRect rect;
	for (int y = 0; y <= image_count_y; y++)
	{
		for (int x = 0; x <= image_count_x; x++)
		{
			rect.left = x * tilewidth;
			rect.top = y * tileheight;
			rect.width = tilewidth;
			rect.height = tileheight;
			image_rects.push_back(rect);
			cout << rect.left << " " << rect.top << " " << rect.width << " " << rect.height << endl;
		}
	}

	XMLElement* layer = root->FirstChildElement("layer");
	while (layer)
	{
		string layer_name = layer->Attribute("name");
		LayerChunks* layer_chunks = new LayerChunks(layer_name);

		XMLElement* chunk = layer->FirstChildElement("data")->FirstChildElement("chunk");
		while (chunk)
		{
			int chunk_pos_x = chunk->IntAttribute("x") * tilewidth;
			int chunk_pos_y = chunk->IntAttribute("y") * tileheight;
			int chunk_width = chunk->IntAttribute("width");
			int chunk_height = chunk->IntAttribute("height");

			int element_pos_x = 0;
			int element_pos_y = 0;

			string chunk_text = chunk->GetText();
			size_t size = chunk_text.size();
			string num;
			for (size_t i = 0; i < size; i++)
			{
				if (chunk_text[i] == ',' || i == (size - 1))
				{
					int tile_id = stoi(num) - firstgid;
					
					if (tile_id >= 0)
					{
						sf::Sprite sprite;
						sprite.setTexture(texture_map);
						sprite.setTextureRect(image_rects[tile_id]);
						sprite.setPosition({ float(chunk_pos_x + element_pos_x * tilewidth), float(chunk_pos_y + element_pos_y * tileheight) });
						layer_chunks->pushSprite(sprite);
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

			chunk = chunk->NextSiblingElement("chunk");
		}

		pushLayer(layer_chunks);
		layer = layer->NextSiblingElement("layer");
	}
}

void captain_lite::World::pushLayer(ILayer* layer)
{
	push_back(layer);
}

cpSpace* World::getSpace()
{
	return space;
}

LightSystem* captain_lite::World::getLightSystem()
{
	return &light_system;
}

void World::update()
{
	cpSpaceStep(World::getInstance()->getSpace(), Window::getInstance()->getDeltaTime());

	for (ILayer* entity : *this)
	{
		entity->update();
	}
}

void World::draw()
{
	for (ILayer* entity : *this)
	{
		entity->draw();
	}

	light_system.draw();
}
