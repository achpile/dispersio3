#ifndef __FRAMEWORK_STRING_PAIR_INL
#define __FRAMEWORK_STRING_PAIR_INL


/***********************************************************************
     * pair_get_string

***********************************************************************/
template <typename T>
const char *pair_get_string(T val, ach::Pair<T> pairs[])
{
	for (int i = 0; pairs[i].str; i++)
		if (val == pairs[i].num)
			return pairs[i].str;

	return NULL;
}



/***********************************************************************
     * pair_get_enum

***********************************************************************/
template <typename T>
T pair_get_enum(const char * val, ach::Pair<T> pairs[])
{
	if (!val)
		return (T)0;

	int i;

	for (i = 0; pairs[i].str; i++)
		if (!strcmp(val, pairs[i].str))
			break;

	return pairs[i].num;
}



/***********************************************************************
     * pair_has_enum

***********************************************************************/
template <typename T>
bool pair_has_enum(T val, ach::Pair<T> pairs[])
{
	for (int i = 0; pairs[i].str; i++)
		if (val == pairs[i].num)
			return true;

	return false;
}

#endif
