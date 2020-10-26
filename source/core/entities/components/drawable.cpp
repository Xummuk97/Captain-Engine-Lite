#include "drawable.h"
#include <core/core.h>

void DrawableComponent::Update(Entity& object)
{
}

void DrawableComponent::Draw(Entity& object)
{
	Core::windowInstance->draw(object.GetSprite());
}
