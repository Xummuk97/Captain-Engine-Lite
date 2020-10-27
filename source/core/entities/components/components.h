#pragma once
#include <core/includes.h>

template<class T>
class IComponent
{
public:
	IComponent() = default;
	virtual ~IComponent() = default;

	virtual void Load(T& object) = 0;
	virtual void Update(T& object) = 0;
	virtual void Draw(T& object) = 0;
};

template<class T>
class ComponentsManager
{
	unordered_map<string, shared_ptr<IComponent<T>>> _data;
	T& _object;

public:
	ComponentsManager(T& object) : _object(object) {}
	virtual ~ComponentsManager() = default;

	void AddComponent(const string& name, const shared_ptr<IComponent<T>>& component)
	{
		_data[name] = component;
		_data[name]->Load(_object);
	}

	void UpdateComponents()
	{
		for (auto [name, component] : _data)
		{
			component->Update(_object);
		}
	}

	void DrawComponents()
	{
		for (auto [name, component] : _data)
		{
			component->Draw(_object);
		}
	}
};