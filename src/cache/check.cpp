#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * isReturn

***********************************************************************/
bool ach::Cache::isReturn()
{
	return false;
}



/***********************************************************************
     * Cache
     * isBeaten

***********************************************************************/
bool ach::Cache::isBeaten(const char *level)
{
	return json_object_getv_branch_boolean(cache, "Map.%s.Finished", level);
}
