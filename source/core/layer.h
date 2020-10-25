#pragma once
#include <core/includes.h>
#include <core/entity.h>

class ILayer
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual string GetName() const = 0;
};

class EntitiesLayer : public ILayer
{
	list<shared_ptr<Entity>> _entities;

public:
	EntitiesLayer() = default;
	~EntitiesLayer() = default;

	void PushEntity(const shared_ptr<Entity>& entity);

	void Update() override;
	void Draw() override;

	string GetName() const override;
};