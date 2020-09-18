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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(1000.0f * Window::getInstance()->getDeltaTime(), 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0.0f, 1000.0f * Window::getInstance()->getDeltaTime());
	}
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
