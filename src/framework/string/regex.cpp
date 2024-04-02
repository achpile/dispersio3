#include "meta/headers.hpp"


/***********************************************************************
     * str_check_check

***********************************************************************/
bool str_check_check(const char *str, const char *expr)
{
	regex_t regex;
	int ret = regcomp(&regex, expr, REG_NOSUB | REG_EXTENDED);

	if (ret)
		return false;

	ret = regexec(&regex, str, 0, NULL, 0);
	regfree(&regex);

	return !ret;
}
