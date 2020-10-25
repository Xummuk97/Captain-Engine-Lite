#pragma once
#include <core/includes.h>
#include <core/entities/entity.h>

class ILayer
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual string GetName() const = 0;
	virtual void PushEntity(const shared_ptr<Entity>& entity) = 0;
};

class EntitiesLayer : public ILayer
{
	list<shared_ptr<Entity>> _entities;

public:
	EntitiesLayer() = default;
	~EntitiesLayer() = default;

	void Update() override;
	void Draw() override;

	string GetName() const override;
	void PushEntity(const shared_ptr<Entity>& entity);
};