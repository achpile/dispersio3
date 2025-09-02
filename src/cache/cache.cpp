#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * constructor

***********************************************************************/
ach::Cache::Cache()
{
	campaign = json_object_get_branch(dm->data, "Data.Game.Campaign");
	cache    = json_object_get_branch(dm->data, "Data.Game.Cache");

	def      = json_object_get_branch_boolean(cache, "Default");
}



/***********************************************************************
     * Cache
     * destructor

***********************************************************************/
ach::Cache::~Cache()
{
	if (!def)
		save();
}



/***********************************************************************
     * Cache
     * init

***********************************************************************/
void ach::Cache::init()
{
	deaths   = json_object_get_branch_integer(cache, "Stats.Deaths");
	playtime = json_object_get_branch_real   (cache, "Stats.Time");

	select(json_object_get_branch_string(cache, "Current.Map"));
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
     * store

***********************************************************************/
void ach::Cache::store()
{
	def = false;

	save();
}



/***********************************************************************
     * Cache
     * reset

***********************************************************************/
void ach::Cache::reset(const char *_mode)
{
	mode  = pair_get_enum(_mode, pairGameMode);
	cache = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache"));

	json_object_set_branch(dm->data, "Data.Game.Cache", cache);
	json_object_set_branch_string(cache, "Current.Map", json_object_get_string(campaign, "Start"));
	json_object_set_string       (cache, "Difficulty" , _mode);
}



/***********************************************************************
     * Cache
     * select

***********************************************************************/
void ach::Cache::select(const char *map)
{
	current = db->getMap(map);

	info = json_object_getv_branch(cache, "Map.%s", map);

	if (!info)
	{
		info = json_dm_generate_default(NULL, json_object_get_branch(dm->dm, "Data.Game.Cache.Map"));

		json_object_setv_branch(cache, info, "Map.%s", map);
	}

	json_object_set_branch_string (cache, "Current.Map"       , map);
	json_object_set_branch_integer(cache, "Current.Checkpoint", -1 );

	if (!def)
		store();
}



/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}
