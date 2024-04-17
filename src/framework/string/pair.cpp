#include "meta/headers.hpp"


/***********************************************************************
     * pair_get_string

***********************************************************************/
const char *pair_get_string(int val, ach::Pair pairs[])
{
	for (int i = 0; pairs[i].str; i++)
		if (val == pairs[i].num)
			return pairs[i].str;

	return NULL;
}



/***********************************************************************
     * pair_get_enum

***********************************************************************/
int pair_get_enum(const char * val, ach::Pair pairs[])
{
	if (!val)
		return 0;

	int i;

	for (i = 0; pairs[i].str; i++)
		if (!strcmp(val, pairs[i].str))
			break;

	return pairs[i].num;
}
