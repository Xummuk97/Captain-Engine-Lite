#pragma once
#include <map>
#include <core/properties.h>

using namespace std;

namespace captain_lite
{
	template<class T>
	class Events
	{
	public:
		Events(T* sender)
			: sender(sender)
		{}

		~Events()
		{}

		void bindEvent(const string& name, void(*F)(T* sender, Properties* properties))
		{
			events[name] = F;
		}
		
		void callEvent(const string& name, Properties* properties = nullptr)
		{
			if (events.find(name) != events.end())
			{
				events[name](sender, properties);
			}
		}

	private:
		T* sender;
		map<string, void(*)(T*, Properties*)> events;
	};
}