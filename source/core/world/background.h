#pragma once
#include <core/includes.h>

namespace captain_lite
{
	class Background : public Singleton<Background>
	{
	public:
		Background();
		Background(const string& texture_name, int x, int y, int width, int height);
		~Background();

		void setTexture(const string& texture_name, int x, int y, int width, int height);

		void update();
		void draw();

	private:
		sf::Sprite sprite;
	};
}