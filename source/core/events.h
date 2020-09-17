#pragma once
#include <core/includes.h>

namespace captain_lite
{
	template<class T>
	class Events
	{
	public:
		using F = void(*) (T* sender);
		
		Events(T* sender)
			: sender(sender)
		{}

		~Events()
		{}

		void bindEvent(const string& name, F f)
		{
			events[name] = F;
		}

		void callEvent(const string& name)
		{
			events[name](sender);
		}

	private:
		T* sender;
		map<string, F> events;
	};
}