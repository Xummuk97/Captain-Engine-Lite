#include "level.h"

void Level::PushLayer(const string& name, const shared_ptr<ILayer>& layer)
{
	_layers[name] = layer;
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
