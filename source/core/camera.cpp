#include "camera.h"
#include <core/window.h>

using namespace captain_lite;

Camera::Camera(float x, float y, float width, float height)
	: Singleton(this)
{
	view.reset({ x, y, width, height} );
}

void Camera::bind(Entity* entity)
{
	this->entity = entity;
}

void Camera::update()
{
	Window::getInstance()->getRenderWindow()->setView(view);

	sf::FloatRect rect = entity->getGlobalBounds();
	view.setCenter(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

	visible_rect = getVisibleRect();
}

sf::FloatRect Camera::getVisibleRect()
{
	sf::Vector2f position = view.getCenter();
	sf::Vector2f size = view.getSize();

	return sf::FloatRect(position.x - size.x / 2.0f, position.y - size.y / 2.0f, size.x, size.y);
}

bool Camera::isVisible(Entity* entity)
{
	return visible_rect.intersects(entity->getGlobalBounds());
}
