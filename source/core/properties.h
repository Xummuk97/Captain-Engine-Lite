#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <any>

#include <tinyxml2/tinyxml2.h>

using namespace std;
using namespace tinyxml2;

namespace captain_lite
{
	class Properties
	{
	public:
		Properties();
		~Properties();

		void setProperty(const string& name, char* value);
		void setProperty(const string& name, const char* value);
		void setProperty(const string& name, any value);

		template<class T>
		T getProperty(const string& name)
		{
			return any_cast<T>(properties[name]);
		}

	private:
		map<string, any> properties;
	};
}