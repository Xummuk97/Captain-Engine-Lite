#include <core/world/camera.h>
#include <core/window.h>
#include <core/world/resource.h>

using namespace captain_lite;

Camera::Camera()
	: Singleton(this)
{
}

Camera::Camera(float x, float y, float width, float height)
	: Singleton(this)
{
	reset(x, y, width, height);
}

Camera::Camera(float x, float y, float width, float height, Entity* entity)
	: Camera(x, y, width, height)
{
	bindEntity(entity);
}

Camera::~Camera()
{
}

void Camera::bindEntity(Entity* entity)
{
	this->entity = entity;
}

void Camera::update()
{
	if (entity)
	{
		sf::FloatRect rect = entity->getGlobalBounds();
		view.setCenter(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

		visible_rect = getVisibleRect();

		Window::getInstance()->setView(view);
	}
}

sf::FloatRect Camera::getVisibleRect()
{
	sf::Vector2f position = view.getCenter();
	sf::Vector2f size = view.getSize();

	return sf::FloatRect(position.x - size.x / 2.0f, position.y - size.y / 2.0f, size.x, size.y);
}

bool Camera::isVisible(Entity* entity)
{
	return isVisible(entity->getGlobalBounds());
}

bool Camera::isVisible(const sf::FloatRect& rect)
{
	return visible_rect.intersects(rect);
}

void Camera::reset(float x, float y, float width, float height)
{
	view.reset({ x, y, width, height });
}
