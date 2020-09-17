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

	class LayerChunks : public ILayer
	{
	public:
		LayerChunks(const string& name);
		~LayerChunks();

		void pushSprite(const sf::Sprite& sprite);

		void update();
		void draw();
		LayerType getType();

	private:
		vector<sf::Sprite> sprites;
	};
}