#pragma once
#include <map>

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

		void bindEvent(const string& name, void(*F)(T* sender))
		{
			events[name] = F;
		}
		
		void callEvent(const string& name)
		{
			if (events.find(name) != events.end())
			{
				events[name](sender);
			}
		}

	private:
		T* sender;
		map<string, void(*)(T*)> events;
	};
}