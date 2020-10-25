#include "level.h"

void Level::PushLayer(const string& name, shared_ptr<ILayer> layer)
{
	if (!HasLayer(name))
	{
		_layers[name] = layer;
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

void Level::PushEntity(const string& layer, shared_ptr<Entity> entity)
{
	if (HasLayer(layer))
	{
		_layers[layer]->PushEntity(move(entity));
	}
	else
	{
		throw "[Level::PushEntity] Error: Layer '" + layer + "' not found.";
	}
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
