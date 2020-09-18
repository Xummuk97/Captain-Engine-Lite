#pragma once
#include <core/includes.h>
#include <core/world/entity.h>

namespace captain_lite
{
	enum struct LayerType
	{
		Objects,
		Chunks
	};

	class ILayer 
	{
	public:
		ILayer(const string& name);
		virtual ~ILayer();

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual LayerType getType() = 0;

		string getName();

	private:
		string name;
	};

	class LayerObjects : public ILayer
	{
	public:
		LayerObjects(const string& name);
		~LayerObjects();

		void pushEntity(Entity* entity);

		void update();
		void draw();
		LayerType getType();

	private:
		list<Entity*> entities;
	};

	class Chunk
	{
	public:
		Chunk();
		~Chunk();

		void setRect(float x, float y, float width, float height);
		sf::FloatRect getRect();
		void pushSprite(const sf::Sprite& sprite);
		
		void draw();

	private:
		sf::FloatRect rect_chunk;
		vector<sf::Sprite> sprites;
	};

	class LayerChunks : public ILayer
	{
	public:
		LayerChunks(const string& name);
		~LayerChunks();

		void pushChunk(Chunk* chunk);

		void update();
		void draw();
		LayerType getType();

	private:
		vector<Chunk*> chunks;
	};
}