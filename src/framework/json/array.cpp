#include "meta/headers.hpp"


/***********************************************************************
     * json_array_contains

***********************************************************************/
bool json_array_contains(json_t *arr, const char *str)
{
	json_t *obj;
	size_t  i;

	json_array_foreach(arr, i, obj)
		if (!strcmp(str, json_string_value(obj)))
			return true;

	return false;
}
