#include "core.h"
#include <core/macros.h>

ResourceManager										Core::resourceManagerInstance;

Level												Core::levelInstance;
Space												Core::spaceInstance;

unique_ptr<sf::RenderWindow>						Core::windowInstance;
unique_ptr<INIReader>								Core::readerInstance;

float												Core::deltaTimeInstance;

Core::Core()
{
	readerInstance = make_unique<INIReader>(PATH_SETTINGS);

	long width = readerInstance->GetInteger("core", "width", 800);
	long height = readerInstance->GetInteger("core", "height", 600);
	string title = readerInstance->GetString("core", "title", "Game");
	bool isFullscreen = readerInstance->GetBoolean("core", "fullscreen", false);
	windowInstance = make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title, isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	
	long fps = readerInstance->GetInteger("core", "fps", 60);
	bool isVerticalSync = readerInstance->GetBoolean("core", "vertical_sync", false);
	windowInstance->setFramerateLimit(fps);
	windowInstance->setVerticalSyncEnabled(isVerticalSync);

	ImGui::SFML::Init(*windowInstance);

	long gravity_x = readerInstance->GetInteger("game", "gravity_x", 0);
	long gravity_y = readerInstance->GetInteger("game", "gravity_y", 100);
	spaceInstance.setGravity(Vect(gravity_x, gravity_y));
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
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					windowInstance->close();
				}
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
