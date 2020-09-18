#include <core/world/background.h>
#include <core/world/resource.h>
#include <core/world/camera.h>
#include <core/window.h>

using namespace captain_lite;

Background::Background()
	: Singleton(this)
{
}

Background::Background(const string& texture_name, int x, int y, int width, int height)
	: Singleton(this)
{
	setTexture(texture_name, x, y, width, height);
}

Background::~Background()
{
}

void Background::setTexture(const string& texture_name, int x, int y, int width, int height)
{
	Utils::loadTextureFromResources(texture_name, sprite, x, y, width, height);
}

void Background::update()
{
	sf::FloatRect visible_rect = Camera::getInstance()->getVisibleRect();
	sprite.setPosition({ visible_rect.left, visible_rect.top });
}

void Background::draw()
{
	Window::getInstance()->draw(sprite);
}
