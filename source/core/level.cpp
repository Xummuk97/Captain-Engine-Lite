#include "level.h"

void Level::PushLayer(const string& name, shared_ptr<ILayer>& layer)
{
	if (!HasLayer(name))
	{
		_layers[name] = layer;
		layer.reset();
	}
	else
	{
		throw "[Level::PushLayer] Error: Layer '" + name + "' found.";
	}
}

bool Level::HasLayer(const string& name)
{
	return _layers.find(name) != _layers.end();
}

void Level::RemoveLayer(const string& name)
{
	if (HasLayer(name))
	{
		_layers.erase(name);
	}
	else
	{
		throw "[Level::PushEntity] Error: Layer '" + name + "' not found.";
	}
}

weak_ptr<ILayer> Level::GetLayer(const string& name)
{
	if (!HasLayer(name))
	{
		throw "[Level::PushEntity] Error: Layer '" + name + "' not found.";
	}
	
	return _layers[name];
}

void Level::Update()
{
	for (auto [name, layer] : _layers)
	{
		layer->Update();
	}
}

void Level::Draw()
{
	for (auto [name, layer] : _layers)
	{
		layer->Draw();
	}
}
