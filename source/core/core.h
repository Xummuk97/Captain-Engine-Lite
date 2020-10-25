#pragma once
#include <core/includes.h>
#include <core/level.h>
#include <core/resources/resource.h>

class Core
{
public:
	Core(const string& title, int width, int height);
	virtual ~Core() = default;

	void Start();

	static ResourceManager resourceManagerInstance;
	static Level levelInstance;
	static Space spaceInstance;

	static sf::RenderWindow* windowInstance;

	static float deltaTimeInstance;
};