#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * init

***********************************************************************/
void ach::Cache::init()
{
	current    = NULL;
	process    = NULL;
	finished   = false;

	cache      = json_object_get_branch(dm->data, "Data.Game.Cache");

	mode       = pair_get_enum(json_object_get_branch_string(cache, "Current.Mode"), pairLevelMode );
	difficulty = pair_get_enum(json_object_get_string       (cache, "Difficulty"  ), pairDifficulty);

	cash       = json_object_get_branch_integer(cache, "Stats.Cash");
	deaths     = json_object_get_branch_integer(cache, "Stats.Deaths");
	playtime   = json_object_get_branch_real   (cache, "Stats.Time");
	leveltime  = json_object_get_branch_real   (cache, "Stats.Level");

	pick(json_object_get_branch_string(cache, "Current.Map"), mode, isDefault());
}



/***********************************************************************
     * Cache
     * save

***********************************************************************/
void ach::Cache::save()
{
	json_object_set_branch (cache, "Stats.Cash"  , json_integer(cash     ));
	json_object_set_branch (cache, "Stats.Deaths", json_integer(deaths   ));
	json_object_set_branch (cache, "Stats.Time"  , json_real   (playtime ));
	json_object_set_branch (cache, "Stats.Level" , json_real   (leveltime));

	if (mode != ach::LevelMode::lmTraining)
	{
		json_object_set_boolean(cache, "Default", false);
		json_dump_file(cache, FILE_CACHE, JSON_INDENT(4) | JSON_SORT_KEYS);
		checksum->store(FILE_CACHE);
	}
}



/***********************************************************************
     * Cache
     * clear

***********************************************************************/
void ach::Cache::clear()
{
	current  = NULL;
	process  = NULL;
	finished = false;
	cache    = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	json_object_set_branch(dm->data, "Data.Game.Cache", cache);

	file_erase(FILE_CACHE);
	checksum->store(FILE_CACHE);
}



/***********************************************************************
     * Cache
     * reset

***********************************************************************/
void ach::Cache::reset(ach::Difficulty _difficulty)
{
	current = NULL;
	process = NULL;
	cache   = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	json_object_set_branch(dm->data, "Data.Game.Cache", cache);
	json_object_set_branch_string(cache, "Current.Map", json_object_get_string(campaign, "Start"));
	json_object_set_string(cache, "Difficulty", pair_get_string(_difficulty, pairDifficulty));

	file_erase(FILE_CACHE);
	checksum->store(FILE_CACHE);
}



/***********************************************************************
     * Cache
     * train

***********************************************************************/
void ach::Cache::train(const char *map)
{
	current = NULL;
	process = NULL;
	cache   = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	mode       = ach::LevelMode::lmTraining;
	difficulty = ach::Difficulty::gdEasy;

	deaths     = 0;
	playtime   = 0.0f;
	leveltime  = 0.0f;

	pick(map, mode, false);
}



/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}
