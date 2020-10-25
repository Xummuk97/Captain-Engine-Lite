#pragma once
#include <core/resources/resource.h>
#include <core/core.h>

class System
{
public:
	static ResourceManager resourceManager;
	static Level level;
	static Space space;

	static sf::RenderWindow* window;

	static float deltaTime;
};