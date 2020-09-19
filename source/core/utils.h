#pragma once
#include <SFML/Graphics.hpp>
#include <tinyxml2/tinyxml2.h>

#include <string>

using namespace tinyxml2;
using namespace std;

namespace captain_lite
{
	class Utils
	{
	public:
		static sf::Vector2f getXmlAttributeVector2f(XMLElement* element);
		static sf::FloatRect getXmlAttributeFloatRect(XMLElement* element);

		static void loadTextureFromResources(const string& texture_name, sf::Sprite& sprite, int x, int y, int width, int height);

		static string toString(int x);
		static string toString(unsigned int x);
		static string toString(long x);
		static string toString(unsigned long x);
		static string toString(long long x);
		static string toString(unsigned long long x);
		static string toString(float x);
		static string toString(double x);
		static string toString(long double x);
		static string toString(const char* x);
		static string toString(char* x);
		static string toString(const string& x);

		template<class T>
		static string toString(T value)
		{
			std::stringstream ss;
			ss << value;
			return ss.str();
		}

		template<class T>
		static T fromString(const string& str)
		{
			std::stringstream ss(str);
			T value;
			ss >> value;
			return value;
		}

		template<class ... Args>
		static string format(const string& message, Args ... args)
		{
			string result;
			string str_args[] = { Utils::toString(args)... };
			size_t size = message.size();

			for (size_t i = 0; i < size; i++)
			{
				if (message[i] != '{')
				{
					result += message[i];
				}
				else
				{
					i++;
					string index;

					while (i < size && message[i] != '}')
					{
						index += message[i];
						i++;
					}

					result += str_args[(size_t)stoi(index) - 1];
				}
			}

			return result;
		}

		static const tm* getTime();

		// http://cplusplus.com/reference/ctime/strftime/
		static string formatTime(const tm* ti, const string& fmt);
	};
}