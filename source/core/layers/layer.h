#pragma once
#include <core/includes.h>
#include <core/entities/entity.h>

class ILayer
{
public:
	ILayer() = default;
	virtual ~ILayer() = default;

	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual string GetName() const = 0;
	virtual void PushEntity(shared_ptr<Entity> entity) = 0;
};

class EntitiesLayer : public ILayer
{
	list<shared_ptr<Entity>> _entities;

public:
	EntitiesLayer() = default;
	virtual ~EntitiesLayer() = default;

	void Update() override;
	void Draw() override;

	string GetName() const override;
	void PushEntity(shared_ptr<Entity> entity);
};