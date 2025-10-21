#include "meta/headers.hpp"


/***********************************************************************
     * Log
     * constructor

***********************************************************************/
ach::Log::Log(ach::LogLevel _level)
{
	level = _level;

	log(ach::LogLevel::llInfo, PROJECT_NAME " v" PROJECT_VERS " started");
}



/***********************************************************************
     * Log
     * destructor

***********************************************************************/
ach::Log::~Log()
{
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
void ach::Log::log(ach::LogLevel _level, const char *format, ...)
{
	if (level > _level)
		return;

	char buf[STR_LEN_LOG];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, STR_LEN_LOG, format, args);
	va_end(args);

	update();

	put(stdout , buf, _level);
}



/***********************************************************************
     * Log
     * put

***********************************************************************/
void ach::Log::put(FILE *fp, const char *str, ach::LogLevel _level)
{
	if (!fp)
		return;

	fprintf(fp, "[%02d:%02d:%02d] [ %-4s ]: %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, pair_get_string(_level, pairLog), str);
	fflush(fp);
}
