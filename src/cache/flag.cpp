#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * getFlag

***********************************************************************/
bool ach::Cache::getFlag(const char *name)
{
	return json_object_getv_branch_boolean(cache, "Flags.%s", name);
}



/***********************************************************************
     * Cache
     * setFlag

***********************************************************************/
void ach::Cache::setFlag(const char *name)
{
	json_object_setv_branch_boolean(cache, true, "Flags.%s", name);
}
