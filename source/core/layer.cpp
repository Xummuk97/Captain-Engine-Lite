#include "layer.h"

void EntitiesLayer::PushEntity(const shared_ptr<Entity>& entity)
{
	_entities.push_back(entity);
}

void EntitiesLayer::Update()
{
	for (auto entity : _entities)
	{
		entity->Update();
	}
}

void EntitiesLayer::Draw()
{
	for (auto entity : _entities)
	{
		entity->Draw();
	}
}

string EntitiesLayer::GetName() const
{
	return "entities";
}
