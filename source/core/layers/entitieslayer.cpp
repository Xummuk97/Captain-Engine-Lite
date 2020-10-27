#include "layer.h"

void EntitiesLayer::PushEntity(shared_ptr<Entity>& entity)
{
	_entities.push_back(entity);
	entity.reset();
}

void EntitiesLayer::Update()
{
	for (auto entity : _entities)
	{
		entity->UpdateComponents();
	}
}

void EntitiesLayer::Draw()
{
	for (auto entity : _entities)
	{
		entity->DrawComponents();
	}
}

string EntitiesLayer::GetName() const
{
	return "entities";
}
