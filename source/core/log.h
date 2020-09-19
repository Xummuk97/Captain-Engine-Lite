#pragma once
#include <core/utils.h>
#include <fstream>

using namespace std;

#define CAPTAIN_LITE_LOG_INFO __FILE__, __FUNCTION__, __LINE__

#define MY_DEBUG
#define MY_ERROR

namespace captain_lite
{
	const string LOG_FILE = "log.txt";

	class Log
	{
	public:
		template<class ... Args>
		static void PrintDebug(const string& file, const string& function, int line, const string& message, Args ... args)
		{
#ifdef MY_DEBUG
			string fmt = Utils::format(message, args ...);
			fmt = Utils::format(message, args ...);
			Log::PrintToFile("DEBUG", file, function, line, fmt);
#endif
		}

		template<class ... Args>
		static void PrintError(const string& file, const string& function, int line, const string& message, Args ... args)
		{
#ifdef MY_ERROR
			string fmt = Utils::format(message, args ...);
			fmt = Utils::format(message, args ...);
			Log::PrintToFile("ERROR", file, function, line, fmt);
			system("pause");
			exit(EXIT_FAILURE);
#endif
		}

	private:
		static void PrintToFile(const string& prefix, const string& file, const string& function, int line, const string& fmt)
		{
			string message = Utils::format("[{1}] {2}\nTime: {3}\nFile: {4}\nFunction: {5}\nLine: {6}", prefix, fmt, Utils::formatTime(Utils::getTime(), "%F %T"), file, function, line);
			cout << message << endl;

			ofstream fout(LOG_FILE, ofstream::app);
			fout << message << endl;
			fout.close();
		}
	};
}