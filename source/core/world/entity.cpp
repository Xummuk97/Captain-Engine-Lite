#include <core/world/entity.h>
#include <core/window.h>
#include <core/world/resource.h>
#include <core/world/world.h>
#include <core/world/camera.h>

using namespace captain_lite;

Entity::Entity(const string& texture_name, int x, int y, int width, int height)
	: Components(this)
	, Events(this)
{
	sprite.setTexture(Resources::getInstance()->get<ResourceTexture>(texture_name));
	sprite.setTextureRect({ x, y, width, height });
}

Entity::~Entity()
{
}

void Entity::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(float x, float y)
{
	float deltaTime = Window::getInstance()->getDeltaTime();
	sprite.move(x * deltaTime, y * deltaTime);
}

sf::Vector2f Entity::getOriginPosition()
{
	sf::FloatRect rect = sprite.getGlobalBounds();
	return { rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f };
}

sf::FloatRect Entity::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void Entity::update()
{
	updateComponents();
}

void Entity::draw()
{
	drawComponents();
}

void Entity::drawSprite()
{
	if (Camera::getInstance()->isVisible(this))
	{
		Window::getInstance()->draw(sprite);
	}
}

EntityInfo::EntityInfo(const sf::FloatRect& rect)
	: rect(rect)
{
}

EntityInfo::~EntityInfo()
{
}
