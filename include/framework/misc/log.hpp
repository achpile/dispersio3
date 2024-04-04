#ifndef __FRAMEWORK_MISC_LOG
#define __FRAMEWORK_MISC_LOG


namespace ach
{
	enum LogLevel
	{
		llInfo = 0,
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

		const char* getLevel(ach::LogLevel level);
	};
}

#endif
