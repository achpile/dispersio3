#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * isRevert

***********************************************************************/
bool ach::Cache::isRevert()
{
	switch (mode)
	{
		case ach::LevelMode::lmDream     : return true;
		case ach::LevelMode::lmReplay    : return true;
		case ach::LevelMode::lmTraining  : return true;
		case ach::LevelMode::lmNavigation: return false;
	}

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
