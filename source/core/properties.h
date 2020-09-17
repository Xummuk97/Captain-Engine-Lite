#pragma once
#include <map>
#include <string>

using namespace std;

namespace captain_lite
{
	union PropertyUnion
	{
		int int_value;
		float float_value;
		string string_value;

		PropertyUnion() 
			: string_value("")
		{}

		~PropertyUnion() {}
	};

	class Properties
	{
	public:
		Properties();
		~Properties();

		void setProperty(const string& name, int value);
		void setProperty(const string& name, float value);
		void setProperty(const string& name, const string& value);

		int getPropertyInt(const string& name);
		float getPropertyFloat(const string& name);
		string getPropertyString(const string& name);

	private:
		map<string, PropertyUnion> properties;
	};
}