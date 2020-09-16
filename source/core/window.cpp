#include "window.h"
#include <core/world.h>
#include <core/camera.h>

using namespace captain_lite;

Window::Window(const string& title, int width, int height)
	: Singleton(this)
{
	render_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Window::exec()
{
	while (render_window->isOpen())
	{
		sf::Event event;
        while (render_window->pollEvent(event))
        {
			switch (event.type)
			{
			case sf::Event::Closed:
				Window::getInstance()->getRenderWindow()->close();
				break;

			case sf::Event::KeyPressed:

				break;
			}
        }

		time = clock.restart();
		deltaTime = time.asSeconds();
		World::getInstance()->update();
		Camera::getInstance()->update();

		render_window->clear();
		Camera::getInstance()->draw();
		World::getInstance()->draw();
		render_window->display();

	}

}

sf::RenderWindow* Window::getRenderWindow()
{
	return render_window;
}

sf::Clock* Window::getClock()
{
	return &clock;
}

sf::Time* Window::getTime()
{
	return &time;
}

float Window::getDeltaTime()
{
	return deltaTime;
}
