#pragma once
#include <core/includes.h>

class ResourceManager
{
	template<class T>
	using DataType = unordered_map<string, shared_ptr<T>>;

	DataType<sf::Texture> _dataTexture;
	DataType<sf::Sound> _dataSounds;
	DataType<sf::Music> _dataMusic;

public:
	ResourceManager() = default;
	virtual ~ResourceManager() = default;

	void SetTexture(const string& name, const string& path);
	void SetSound(const string& name, const string& path);
	void SetMusic(const string& name, const string& path);

	shared_ptr<sf::Texture> GetTexture(const string& name);
	shared_ptr<sf::Sound> GetSound(const string& name);
	shared_ptr<sf::Music> GetMusic(const string& name);
};