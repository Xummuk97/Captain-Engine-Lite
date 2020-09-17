#include <core/world/camera.h>
#include <core/window.h>
#include <core/world/resource.h>

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
	if (entity)
	{
		sf::FloatRect rect = entity->getGlobalBounds();
		view.setCenter(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

		visible_rect = getVisibleRect();

		background.setPosition(visible_rect.left, visible_rect.top);

		Window::getInstance()->getRenderWindow()->setView(view);
	}
}

void Camera::draw()
{
	Window::getInstance()->getRenderWindow()->draw(background);
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

void Camera::setBackground(const string& texture_name, int x, int y, int width, int height)
{
	background.setTexture(Resources::getInstance()->get<ResourceTexture>(texture_name));
	background.setTextureRect({ x, y, width, height });
}
