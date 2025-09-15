#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * isDefault

***********************************************************************/
bool ach::Cache::isDefault()
{
	return !file_exists(FILE_CACHE);
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
     * isRevert

***********************************************************************/
bool ach::Cache::isRevert()
{
	switch (mode)
	{
		case ach::LevelMode::lmDream     : return true;
		case ach::LevelMode::lmReplay    : return true;
		case ach::LevelMode::lmTraining  : return false;
		case ach::LevelMode::lmNavigation: return false;
	}

	return false;
}



/***********************************************************************
     * Cache
     * isCutscenes

***********************************************************************/
bool ach::Cache::isCutscenes(ach::LevelMode _mode)
{
	switch (_mode)
	{
		case ach::LevelMode::lmReplay    : return false;
		case ach::LevelMode::lmTraining  : return false;
		case ach::LevelMode::lmNavigation: return settings->isCutscenes();
		case ach::LevelMode::lmDream     : return settings->isCutscenes();
	}

	return false;
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



/***********************************************************************
     * Cache
     * getError

***********************************************************************/
const char* ach::Cache::getError(ach::LevelMode _mode)
{
	switch (_mode)
	{
		case ach::LevelMode::lmReplay    : return "";
		case ach::LevelMode::lmTraining  : return "";
		case ach::LevelMode::lmNavigation: return "";
		case ach::LevelMode::lmDream     : return getErrorDream();
	}

	return "";
}



/***********************************************************************
     * Cache
     * getErrorDream

***********************************************************************/
const char* ach::Cache::getErrorDream()
{
	json_t *item;
	size_t  index;

	size_t count   = 0;
	size_t beaten  = 0;
	size_t missing = 0;

	json_array_foreach(json_object_get(campaign, "Dream"), index, item)
	{
		if (!getFlag(json_object_get_string(item, "Flag")))
		{
			missing++;
			continue;
		}

		if (isBeaten(json_object_get_string(item, "Level")))
		{
			beaten++;
			continue;
		}

		count++;
	}

	if (count)
		return "";

	if (beaten == json_array_size(json_object_get(campaign, "Dream")))
		return "Game.Message.BedOverslept";

	if (missing)
		return "Game.Message.BedFreshener";

	return "";
}
