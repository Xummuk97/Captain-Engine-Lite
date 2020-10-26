#pragma once
#include <core/entities/components/components.h>
#include <core/entities/entity.h>

class DrawableComponent : public IComponent<Entity>
{
public:
	DrawableComponent() = default;
	virtual ~DrawableComponent() = default;

	void Update(Entity& object) override;
	void Draw(Entity& object) override;
};