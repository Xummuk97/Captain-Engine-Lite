#pragma once
#include <core/includes.h>
#include <core/layers/layer.h>

class Level
{
	unordered_map<string, shared_ptr<ILayer>> _layers;

public:
	Level() = default;
	virtual ~Level() = default;

	void PushLayer(const string& name, shared_ptr<ILayer> layer);
	bool HasLayer(const string& name);
	void RemoveLayer(const string& name);

	void PushEntity(const string& layer, shared_ptr<Entity> entity);

	void Update();
	void Draw();
};