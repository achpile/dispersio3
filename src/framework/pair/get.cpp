#include "meta/headers.hpp"


/***********************************************************************
     * pairGetString

***********************************************************************/
const char *pairGetString(int val, ach::Pair pairs[])
{
	for (int i = 0; pairs[i].str; i++)
		if (val == pairs[i].num)
			return pairs[i].str;

	return NULL;
}



/***********************************************************************
     * pairGetEnum

***********************************************************************/
int pairGetEnum(const char * val, ach::Pair pairs[])
{
	if (!val)
		return 0;

	for (int i = 0; pairs[i].str; i++)
		if (!strcmp(val, pairs[i].str))
			return pairs[i].num;

	return 0;
}
