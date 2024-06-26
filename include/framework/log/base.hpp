#ifndef __FRAMEWORK_LOG_BASE
#define __FRAMEWORK_LOG_BASE


namespace ach
{
	enum LogLevel
	{
		llDebug = 0,
		llInfo,
		llWarning,
		llError
	};


	struct Log
	{
		struct tm *tm;
		FILE      *logfile;
		time_t     now;


		 Log();
		~Log();

		void update();

		void log(ach::LogLevel level, const char *format, ...);
		void put(FILE *fp, const char *str, ach::LogLevel level);
	};
}

#endif
