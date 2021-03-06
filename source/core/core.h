#pragma once
#include <core/includes.h>
#include <core/level.h>
#include <core/resources/resource.h>
#include <core/entities/components/drawable.h>
#include <core/entities/components/animation/animation.h>

class Core
{
public:
	Core();
	virtual ~Core() = default;

	void Start();

	static ResourceManager resourceManagerInstance;

	static Level levelInstance;
	static Space spaceInstance;

	static unique_ptr<sf::RenderWindow> windowInstance;
	static unique_ptr<INIReader> readerInstance;

	static float deltaTimeInstance;
};