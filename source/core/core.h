#pragma once
#include <core/includes.h>
#include <core/level.h>

class Core
{
public:
	Core(const string& title, int width, int height);
	virtual ~Core() = default;

	void Start();
};