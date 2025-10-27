#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * goal

***********************************************************************/
void ach::Cache::goal()
{
	if (current->leaderboard)
		records->setLeaderboard(current->name, leveltime);

	if (isCutscenes(mode))
		state = ach::LevelState::lsOutro;
	else
		finish();

	leveltime = 0.0f;
}



/***********************************************************************
     * Cache
     * cutscene

***********************************************************************/
void ach::Cache::cutscene()
{
	if (state == ach::LevelState::lsIntro)
		state =  ach::LevelState::lsLevel;
	else
		finish();
}



/***********************************************************************
     * Cache
     * revert

***********************************************************************/
void ach::Cache::revert()
{
	warp(json_object_get_branch_string(cache, "Current.Origin"), ach::LevelMode::lmNavigation, false);
}



/***********************************************************************
     * Cache
     * finish

***********************************************************************/
void ach::Cache::finish()
{
	beat(current->name);
	json_object_set_boolean(info, "Finished", true);

	if (current->finish)
		finished = true;

	switch (mode)
	{
		case ach::LevelMode::lmNavigation: warp(current->next, ach::LevelMode::lmNavigation, true); break;
		case ach::LevelMode::lmDream     : warp(current->next, ach::LevelMode::lmNavigation, true); break;
		case ach::LevelMode::lmReplay    : revert(); break;

		case ach::LevelMode::lmTraining  :
			json_decref(cache);

			cache    = NULL;
			finished = true;
		break;
	}
}



/***********************************************************************
     * Cache
     * warp

***********************************************************************/
void ach::Cache::warp(const char *map, ach::LevelMode _mode, bool intro)
{
	json_object_set_branch_string (cache, "Current.Map"       , map);
	json_object_set_branch_string (cache, "Current.Mode"      , pair_get_string(_mode, pairLevelMode));
	json_object_set_branch_integer(cache, "Current.Checkpoint", -1 );

	leveltime = 0.0f;

	pick(json_object_get_branch_string(cache, "Current.Map"), _mode, intro);
}



/***********************************************************************
     * Cache
     * pick

***********************************************************************/
void ach::Cache::pick(const char *map, ach::LevelMode _mode, bool intro)
{
	if (current)
		json_object_set_branch_string(cache, "Current.Origin", current->name);

	mode    = _mode;
	current = db->getMap(map);
	info    = json_object_getv_branch(cache, "Map.%s", map);

	if (!info)
	{
		info = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache.Map"));

		json_object_setv_branch(cache, info, "Map.%s", map);
	}


	if (isCutscenes(mode) && intro)
		state = ach::LevelState::lsIntro;
	else
		state = ach::LevelState::lsLevel;

	save();
}
