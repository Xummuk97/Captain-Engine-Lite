#pragma once
#include <core/includes.h>

namespace captain_lite
{
	template<class T>
	class IComponent 
	{
	public:
		IComponent()
		{}

		virtual void update() = 0;
		virtual void draw() = 0;

		void setObject(T* object)
		{
			this->object = object;
		}

	protected:
		T* object;
	};

	template<class T>
	class Components
	{
	public:
		Components(T* object)
			: object(object)
		{}

		~Components() = default;

		void addComponent(IComponent<T>* component)
		{
			component->setObject(object);
			components.push_back(component);
		}
		
		void updateComponents()
		{
			for (IComponent<T>* component : components)
			{
				component->update();
			}
		}

		void drawComponents()
		{
			for (IComponent<T>* component : components)
			{
				component->draw();
			}
		}

	private:
		list<IComponent<T>*> components;
		T* object;
	};
}