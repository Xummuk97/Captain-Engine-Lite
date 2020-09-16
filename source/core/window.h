#pragma once
#include <core/includes.h>
#include <core/singleton.h>

namespace captain_lite
{
	class Window : public Singleton<Window>
	{
	public:
		Window(const string& title, int width, int height);
		~Window() = default;

		void exec();

		sf::RenderWindow* getRenderWindow();
		sf::Clock* getClock();
		sf::Time* getTime();
		float getDeltaTime();

	private:
		sf::RenderWindow* render_window;
		sf::Clock clock;
		sf::Time time;
		float deltaTime;
	};
}