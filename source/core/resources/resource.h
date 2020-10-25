#pragma once
#include <core/includes.h>

struct IResource 
{
	IResource() = default;
	virtual ~IResource() = default;
};

template<class T>
class ResourceData
{
public:
	ResourceData() = default;
	virtual ~ResourceData() = default;

	T& Get() { return *_data.get(); }

protected:
	unique_ptr<T> _data;
};

class TextureResource : public IResource, public ResourceData<sf::Texture>
{
public:
	TextureResource(const string& path);
	virtual ~TextureResource() = default;
};

class SoundResource : public IResource, public ResourceData<sf::Sound>
{
public:
	SoundResource(const string& path);
	virtual ~SoundResource() = default;
};

class MusicResource : public IResource, public ResourceData<sf::Music>
{
public:
	MusicResource(const string& path);
	virtual ~MusicResource() = default;
};

class ResourceManager
{
	unordered_map<string, shared_ptr<IResource>> _data;

public:
	ResourceManager() = default;
	virtual ~ResourceManager() = default;

	void Set(const string& name, const shared_ptr<IResource>& resource);
	bool Has(const string& name);

	template<class T>
	ResourceData<T>& Get(const string& name)
	{
		if (Has(name))
		{
			return *dynamic_pointer_cast<ResourceData<T>>(_data[name]); // IResource->ResourceData<T>
		}
		else
		{
			throw "[ResourceManager::Get] Error: Resource '" + name + "' not found.";
		}
	}
};