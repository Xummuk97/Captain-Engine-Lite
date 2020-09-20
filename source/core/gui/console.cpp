#include <core/gui/console.h>

using namespace captain_lite;

Console::Console()
	: Singleton(this)
	, Events(this)
{
}

Console::~Console()
{
}

void Console::setEnabled()
{
	is_enabled = !is_enabled;
}

void Console::draw()
{
	if (is_enabled)
	{
		ImGui::Begin("Console");
		ImGui::InputTextMultiline("", text, sizeof(text));
		ImGui::InputText("Input command", command, sizeof(command));

		if (ImGui::Button("Run"))
		{
			vector<string> args;
			string arg;
			
			int size = strlen(command) + 1;

			for (int i = 0; i < size; i++)
			{
				if ((command[i] == ' ' || i == (size - 1)) && arg.size() > 0)
				{
					args.push_back(arg);
					arg.clear();
				}
				else
				{
					arg += command[i];
				}
			}

			Properties* properties = new Properties;
			properties->setProperty("args", args);
			callEvent(CAPTAIN_LITE_CONSOLE_EVENT_INPUT_COMMAND, properties);
			delete properties;

			sprintf(text, "%s%s\n", text, command);
			command[0] = 0;
		}

		ImGui::End();
	}
}
