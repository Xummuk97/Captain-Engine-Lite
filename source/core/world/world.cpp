#include <core/world/world.h>
#include <core/world/camera.h>
#include <core/world/background.h>
#include <core/window.h>

using namespace captain_lite;

World::World()
	: Singleton(this)
{
}

World::~World()
{
	//delete space;

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

	int imagewidth = image->IntAttribute("width");
	int imageheight = image->IntAttribute("height");

	int image_count_x = imagewidth / tilewidth;
	int image_count_y = imageheight / tileheight;

	image_rects.clear();
	sf::IntRect rect;
	for (int y = 0; y < image_count_y; y++)
	{
		for (int x = 0; x < image_count_x; x++)
		{
			rect.left = x * tilewidth;
			rect.top = y * tileheight;
			rect.width = tilewidth;
			rect.height = tileheight;
			image_rects.push_back(rect);
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
			Chunk* obj_chunk = new Chunk;

			int chunk_pos_x = chunk->IntAttribute("x") * tilewidth;
			int chunk_pos_y = chunk->IntAttribute("y") * tileheight;
			int chunk_width = chunk->IntAttribute("width");
			int chunk_height = chunk->IntAttribute("height");

			int element_pos_x = 0;
			int element_pos_y = 0;

			obj_chunk->setRect((float)chunk_pos_x, (float)chunk_pos_y, float(chunk_width * tilewidth), float(chunk_height * tileheight));

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
						obj_chunk->pushSprite(sprite);
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

			layer_chunks->pushChunk(obj_chunk);
			chunk = chunk->NextSiblingElement("chunk");
		}

		pushLayer(layer_chunks);
		layer = layer->NextSiblingElement("layer");
	}
}

void World::pushLayer(ILayer* layer)
{
	layers.push_back(layer);
}

void World::clear()
{
	for (ILayer* layer : layers)
	{
		delete layer;
	}
	layers.clear();
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
