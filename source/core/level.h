#pragma once
#include <core/includes.h>
#include <core/layer.h>

class Level
{
	unordered_map<string, shared_ptr<ILayer>> _layers;

public:
	Level() = default;
	virtual ~Level() = default;

	void PushLayer(const string& name, const shared_ptr<ILayer>& layer);

	void Update();
	void Draw();
};