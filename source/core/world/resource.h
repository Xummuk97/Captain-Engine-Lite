#pragma once
#include <core/includes.h>

namespace captain_lite
{
	enum struct ResourceType
	{
		Texture,
		Sound
	};

	struct IResource {};

	class ResourceTexture : public sf::Texture, public IResource 
	{
	public:
		ResourceTexture(const string& file);
		virtual ~ResourceTexture() = default;
	};

	class ResourceSound : public sf::Sound, public IResource 
	{
	public:
		ResourceSound(const string& file);
		virtual ~ResourceSound() = default;
	};

	class Resources : public Singleton<Resources>
	{
	public:
		Resources();
		virtual ~Resources() = default;

		void add(const string& name, IResource* resource);

		template<class T>
		T& get(const string& name)
		{
			return *(T*)resources[name];
		}

	private:
		map<string, IResource*> resources;
	};
}