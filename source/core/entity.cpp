#include "entity.h"
#include <core/window.h>
#include <core/resource.h>
#include <core/world.h>
#include <core/camera.h>

using namespace captain_lite;

Entity::Entity(const string& texture_name, int x, int y, int width, int height)
	: Components(this)
{
	setTexture(Resources::getInstance()->get<ResourceTexture>(texture_name));
	setTextureRect({ x, y, width, height });
}

sf::Vector2f Entity::getOriginPosition()
{
	sf::FloatRect rect = getGlobalBounds();
	return { rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f };
}

void Entity::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(-100.0f * Window::getInstance()->getDeltaTime(), 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(100.0f * Window::getInstance()->getDeltaTime(), 0.0f);
	}

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
		Window::getInstance()->getRenderWindow()->draw(*this);
	}
}