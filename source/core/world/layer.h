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
		~ILayer();

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual LayerType getType() = 0;

		string getName();

	private:
		string name;
	};

	class LayerObjects : public ILayer, public list<Entity*>
	{
	public:
		LayerObjects(const string& name);
		virtual ~LayerObjects();

		void pushEntity(Entity* entity);

		void update();
		void draw();
		LayerType getType();
	};

	class LayerChunks : public ILayer, public vector<sf::Sprite>
	{
	public:
		LayerChunks(const string& name);
		~LayerChunks();

		void pushSprite(const sf::Sprite& sprite);

		void update();
		void draw();
		LayerType getType();
	};
}