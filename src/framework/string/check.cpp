#include "meta/headers.hpp"


/***********************************************************************
     * str_check_start

***********************************************************************/
bool str_check_start(const char *str, const char *start)
{
	return !strncmp(str, start, strlen(start));
}



/***********************************************************************
     * str_check_name

***********************************************************************/
bool str_check_name(const char *str)
{
// ^[[:alnum:]_-]{1,128}$
	return str != NULL;
}



/***********************************************************************
     * str_check_color

***********************************************************************/
bool str_check_color(const char *str)
{
// ^#[[:xdigit:]]{2}{3,4}$
	return str != NULL;
}
