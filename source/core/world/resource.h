#pragma once
#include <core/includes.h>

namespace captain_lite
{
	enum struct ResourceType
	{
		Texture,
		Sound
	};

	struct IResource 
	{
		IResource();
		virtual ~IResource();
	};

	class ResourceTexture : public IResource, public sf::Texture
	{
	public:
		ResourceTexture(const string& file);
		~ResourceTexture();
	};

	class ResourceSound : public IResource, public sf::Sound
	{
	public:
		ResourceSound(const string& file);
		~ResourceSound();
	};

	class Resources : public Singleton<Resources>
	{
	public:
		Resources();
		~Resources();

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