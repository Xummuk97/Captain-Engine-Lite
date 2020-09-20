#pragma once
#include <core/includes.h>

namespace captain_lite
{
	const string CAPTAIN_LITE_CONSOLE_EVENT_INPUT_COMMAND = "EVENT_INPUT_COMMAND";

	class Console : public Singleton<Console>, public Events<Console>
	{
	public:
		Console();
		~Console();

		void setEnabled();

		void draw();

	private:
		bool is_enabled = false;
		char text[1024];
		char command[256];
	};
}