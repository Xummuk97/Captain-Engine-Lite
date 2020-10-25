#include "core.h"
#include <core/system.h>
#include <core/macros.h>

Core::Core(const string& title, int width, int height)
{
	System::window = new sf::RenderWindow(sf::VideoMode(width, height), title);

	ImGui::SFML::Init(*System::window);
	System::space.setGravity(Vect(0, 100));
}

void Core::Start()
{
	sf::Clock clock;

	while (System::window->isOpen())
	{
		sf::Event event;
		while (System::window->pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
			{
				System::window->close();
			}
		}

		sf::Time time = clock.restart();
		System::deltaTime = time.asSeconds();
		ImGui::SFML::Update(*System::window, time);
		System::space.step(1 / 60.0f);
		System::level.Update();
		
		System::window->clear();
		System::level.Draw();
		ImGui::SFML::Render(*System::window);
		System::window->display();
	}
}
