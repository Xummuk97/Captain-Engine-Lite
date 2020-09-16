#pragma once
#include <core/includes.h>
#include <core/entity.h>

namespace captain_lite
{
	enum struct LayerType
	{
		Normal,
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

	private:
		string name;
	};

	class LayerNormal : public ILayer, public list<Entity*>
	{
	public:
		LayerNormal(const string& name);
		virtual ~LayerNormal();

		void pushEntity(Entity* entity);

		void update();
		void draw();
		LayerType getType();
	};
}