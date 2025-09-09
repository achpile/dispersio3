#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * constructor

***********************************************************************/
ach::Cache::Cache()
{
	current  = NULL;
	process  = NULL;
	finished = false;

	campaign = json_object_get_branch(dm->data, "Data.Game.Campaign");
	cache    = json_object_get_branch(dm->data, "Data.Game.Cache");
}



/***********************************************************************
     * Cache
     * destructor

***********************************************************************/
ach::Cache::~Cache()
{
}



/***********************************************************************
     * Cache
     * update

***********************************************************************/
void ach::Cache::update()
{
	playtime += tm->get();
}



/***********************************************************************
     * Cache
     * init

***********************************************************************/
void ach::Cache::init()
{
	current    = NULL;
	process    = NULL;
	finished   = false;

	mode       = pair_get_enum(json_object_get_branch_string(cache, "Current.Mode"), pairLevelMode );
	difficulty = pair_get_enum(json_object_get_string       (cache, "Difficulty"  ), pairDifficulty);

	deaths     = json_object_get_branch_integer(cache, "Stats.Deaths");
	playtime   = json_object_get_branch_real   (cache, "Stats.Time");

	pick(json_object_get_branch_string(cache, "Current.Map"), mode, isDefault());
}



/***********************************************************************
     * Cache
     * save

***********************************************************************/
void ach::Cache::save()
{
	json_object_set_branch (cache, "Stats.Deaths", json_integer(deaths  ));
	json_object_set_branch (cache, "Stats.Time"  , json_real   (playtime));
	json_object_set_boolean(cache, "Default"     , false                 );

	json_dump_file(cache, FILE_CACHE, JSON_INDENT(4) | JSON_SORT_KEYS);
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

	unlink(FILE_CACHE);
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
}



/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}
