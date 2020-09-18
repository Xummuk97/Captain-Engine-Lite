#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <string>

#include <tinyxml2/tinyxml2.h>

using namespace std;
using namespace tinyxml2;

namespace captain_lite
{
	union PropertyUnion
	{
		int int_value;
		float float_value;
		sf::Vector2i vector2i_value;
		sf::Vector2f vector2f_value;
		sf::IntRect intrect_value;
		sf::FloatRect floatrect_value;
		string string_value;
		XMLElement* xmlelement_value;

		PropertyUnion()
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
		void setProperty(const string& name, const sf::Vector2i& value);
		void setProperty(const string& name, const sf::Vector2f& value);
		void setProperty(const string& name, const sf::IntRect& value);
		void setProperty(const string& name, const sf::FloatRect& value);
		void setProperty(const string& name, XMLElement* value);

		int getPropertyInt(const string& name);
		float getPropertyFloat(const string& name);
		string getPropertyString(const string& name);
		sf::Vector2i getPropertyVector2i(const string& name);
		sf::Vector2f getPropertyVector2f(const string& name);
		sf::IntRect getPropertyIntRect(const string& name);
		sf::FloatRect getPropertyFloatRect(const string& name);
		XMLElement* getPropertyXMLElement(const string& name);

	private:
		map<string, PropertyUnion> properties;
	};
}