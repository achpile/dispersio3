#include "meta/headers.hpp"


/***********************************************************************
     * str_check_start

***********************************************************************/
bool str_check_start(const char *str, const char *start)
{
	return !strncmp(str, start, strlen(start));
}
