#include "meta/headers.hpp"


/***********************************************************************
     * str_check_start

***********************************************************************/
bool str_check_start(const char *str, const char *start)
{
	return !strncmp(str, start, strlen(start));
}



/***********************************************************************
     * str_check_regex

***********************************************************************/
bool str_check_regex(const char *str, const char *expr)
{
	return std::regex_match(str, std::regex(expr));
}
