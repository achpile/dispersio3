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



/***********************************************************************
     * Cache
     * isPossible

***********************************************************************/
bool ach::Cache::isPossible(ach::LevelMode _mode)
{
	switch (_mode)
	{
		case ach::LevelMode::lmReplay    : return true;
		case ach::LevelMode::lmTraining  : return true;
		case ach::LevelMode::lmNavigation: return true;
		case ach::LevelMode::lmDream     : return isPossibleDream();
	}

	return false;
}



/***********************************************************************
     * Cache
     * isPossibleDream

***********************************************************************/
bool ach::Cache::isPossibleDream()
{
	json_t *item;
	size_t  index;

	int count = 0;

	json_array_foreach(json_object_get(campaign, "Dream"), index, item)
	{
		if (!getFlag(json_object_get_string(item, "Flag")))
			continue;

		if (isBeaten(json_object_get_string(item, "Level")))
			continue;

		count++;
	}

	return count != 0;
}
