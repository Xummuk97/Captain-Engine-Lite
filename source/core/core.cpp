#include "core.h"
#include <core/macros.h>

ResourceManager										Core::resourceManagerInstance;
Level												Core::levelInstance;
Space												Core::spaceInstance;

sf::RenderWindow*									Core::windowInstance;
float												Core::deltaTimeInstance;

Core::Core(const string& title, int width, int height)
{
	windowInstance = new sf::RenderWindow(sf::VideoMode(width, height), title);
	ImGui::SFML::Init(*windowInstance);

	spaceInstance.setGravity(Vect(0, 100));
}

void Core::Start()
{
	sf::Clock clock;

	while (windowInstance->isOpen())
	{
		sf::Event event;
		while (windowInstance->pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
			{
				windowInstance->close();
			}
		}

		sf::Time time = clock.restart();
		deltaTimeInstance = time.asSeconds();
		ImGui::SFML::Update(*windowInstance, time);
		spaceInstance.step(1 / 60.0f);
		levelInstance.Update();
		
		windowInstance->clear();
		levelInstance.Draw();
		ImGui::SFML::Render(*windowInstance);
		windowInstance->display();
	}
}
