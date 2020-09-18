#include <core/window.h>
#include <core/world/world.h>

using namespace captain_lite;

Window::Window()
	: Window("Captain Engine 1.0", 800, 600)
{
}

Window::Window(const string& title, int width, int height)
	: Singleton(this)
	, render_window(new sf::RenderWindow(sf::VideoMode(width, height), title))
{
	ImGui::SFML::Init(*render_window);
}

Window::~Window()
{
	delete render_window;
}

void Window::exec()
{
	while (render_window->isOpen())
	{
		sf::Event event;
        while (render_window->pollEvent(event))
        {
			ImGui::SFML::ProcessEvent(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				render_window->close();
				break;

			case sf::Event::KeyPressed:

				break;
			}
        }

		time = clock.restart();
		deltaTime = time.asSeconds();
		ImGui::SFML::Update(*render_window, time);
		World::getInstance()->update();

		render_window->clear();
		World::getInstance()->draw();
		ImGui::SFML::Render(*render_window);
		render_window->display();
	}

}

float Window::getDeltaTime()
{
	return deltaTime;
}

void Window::draw(const sf::Sprite& sprite)
{
	render_window->draw(sprite);
}

void Window::draw(sfl::Light& light)
{
	light.Render(*render_window);
}

void Window::draw(sfl::LightScene& light_scene)
{
	light_scene.Render(*render_window);
}

void Window::setView(const sf::View& view)
{
	render_window->setView(view);
}

void Window::setFPSLimit(unsigned int limit)
{
	render_window->setFramerateLimit(limit);
}

void Window::setVerticalSyncEnabled(bool enabled)
{
	render_window->setVerticalSyncEnabled(enabled);
}
