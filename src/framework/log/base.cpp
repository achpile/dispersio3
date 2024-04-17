#include "meta/headers.hpp"


/***********************************************************************
     * Log
     * constructor

***********************************************************************/
ach::Log::Log()
{
	char filename[256];

	arch_mkdir("logs");
	update();

	snprintf(filename, sizeof(filename),
	         "logs/%04d.%02d.%02d_%02d.%02d.%02d.txt",
	         tm->tm_year + 1900,
	         tm->tm_mon + 1,
	         tm->tm_mday,
	         tm->tm_hour,
	         tm->tm_min,
	         tm->tm_sec);

	logfile = fopen(filename, "w");

	log(ach::LogLevel::llInfo, PROJECT_NAME " v" PROJECT_VERS " started");
}



/***********************************************************************
     * Log
     * destructor

***********************************************************************/
ach::Log::~Log()
{
	if (logfile)
		fclose(logfile);
}



/***********************************************************************
     * Log
     * update

***********************************************************************/
void ach::Log::update()
{
	time(&now);

	tm = localtime(&now);
}



/***********************************************************************
     * Log
     * log

***********************************************************************/
void ach::Log::log(ach::LogLevel level, const char *format, ...)
{
	char buf[STR_LEN_LOG];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, STR_LEN_LOG, format, args);
	va_end(args);

	update();

	put(stdout , buf, level);
	put(logfile, buf, level);
}



/***********************************************************************
     * Log
     * put

***********************************************************************/
void ach::Log::put(FILE *fp, const char *str, ach::LogLevel level)
{
	if (!fp)
		return;

	fprintf(fp, "[%02d:%02d:%02d] [ %-4s ]: %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, pair_get_string(level, pairLog), str);
	fflush(fp);
}
