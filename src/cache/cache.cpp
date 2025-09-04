#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * constructor

***********************************************************************/
ach::Cache::Cache()
{
	current  = NULL;

	campaign = json_object_get_branch(dm->data, "Data.Game.Campaign");
	cache    = json_object_get_branch(dm->data, "Data.Game.Cache");
}



/***********************************************************************
     * Cache
     * destructor

***********************************************************************/
ach::Cache::~Cache()
{
	save();
}



/***********************************************************************
     * Cache
     * init

***********************************************************************/
void ach::Cache::init()
{
	current  = NULL;
	mode     = pair_get_enum(json_object_get_branch_string(cache, "Current.Mode"), pairLevelMode);
	state    = ach::LevelState::lsLevel;

	deaths   = json_object_get_branch_integer(cache, "Stats.Deaths");
	playtime = json_object_get_branch_real   (cache, "Stats.Time");
	hard     = json_object_get_boolean       (cache, "Hard");

	if (isDefault())
		state = ach::LevelState::lsIntro;

	select(json_object_get_branch_string(cache, "Current.Map"), mode);
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
     * reset

***********************************************************************/
void ach::Cache::reset(bool _hard)
{
	hard    = _hard;
	current = NULL;
	cache   = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	json_object_set_branch(dm->data, "Data.Game.Cache", cache);
	json_object_set_branch_string(cache, "Current.Map", json_object_get_string(campaign, "Start"));
	json_object_set_boolean      (cache, "Hard"       , hard);
}



/***********************************************************************
     * Cache
     * next

***********************************************************************/
void ach::Cache::next()
{
}



/***********************************************************************
     * Cache
     * select

***********************************************************************/
void ach::Cache::select(const char *map, ach::LevelMode _mode)
{
	if (current)
		json_object_set_branch_string(cache, "Current.Origin", current->name);

	mode    = _mode;
	current = db->getMap(map);

	info = json_object_getv_branch(cache, "Map.%s", map);

	if (!info)
	{
		info = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache.Map"));

		json_object_setv_branch(cache, info, "Map.%s", map);
	}

	json_object_set_branch_string (cache, "Current.Map"       , map);
	json_object_set_branch_string (cache, "Current.Mode"      , pair_get_string(mode, pairLevelMode));
	json_object_set_branch_integer(cache, "Current.Checkpoint", -1 );

	save();
}



/***********************************************************************
     * Cache
     * revert

***********************************************************************/
void ach::Cache::revert()
{
	current = NULL;

	select(json_object_get_branch_string(cache, "Current.Origin"), ach::LevelMode::lmNavigation);
}



/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}
