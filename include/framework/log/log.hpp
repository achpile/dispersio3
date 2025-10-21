#ifndef __FRAMEWORK_LOG_LOG
#define __FRAMEWORK_LOG_LOG


namespace ach
{
	enum LogLevel
	{
		llDebug = 0,
		llInfo,
		llWarning,
		llError,
		llOff
	};


	struct Log
	{
		ach::LogLevel level;

		struct tm *tm;
		time_t     now;


		 Log(ach::LogLevel _level = ach::LogLevel::llInfo);
		~Log();

		void update();

		void log(ach::LogLevel _level, const char *format, ...);
		void put(FILE *fp, const char *str, ach::LogLevel _level);
	};
}

#endif
