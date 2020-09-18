#pragma once
#include <core/includes.h>

namespace captain_lite
{
	const string WINDOW_EVENT_GUI = "EVENT_GUI";

	class Window : public Singleton<Window>, public Events<Window>
	{
	public:
		Window();
		Window(const string& title, int width, int height);
		~Window();

		float getDeltaTime();
		void draw(const sf::Sprite& sprite);
		void setView(const sf::View& view);
		void setFPSLimit(unsigned int limit);
		void setVerticalSyncEnabled(bool enabled);

		void exec();

	private:
		sf::RenderWindow* render_window;
		sf::Clock clock;
		sf::Time time;
		float deltaTime = 0.0f;
	};
}