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
	if (!str)
		return false;

	if (!strlen(str) || strlen(str) >= STR_LEN_NAME)
		return false;

	for (size_t i = 0; i < strlen(str); i++)
		if (!isalnum(str[i]))
			return false;

	return true;
}



/***********************************************************************
     * str_check_color

***********************************************************************/
bool str_check_color(const char *str)
{
	if (!str)
		return false;

	if (!strlen(str) || (strlen(str) != 7 && strlen(str) != 9))
		return false;

	if (str[0] != '#')
		return false;

	for (size_t i = 1; i < strlen(str); i++)
		if (!isxdigit(str[i]))
			return false;

	return true;
}
