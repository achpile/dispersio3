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
     * finish

***********************************************************************/
void ach::Cache::finish()
{
	json_object_set_boolean(info, "Finished", true);

	select(current->next);
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
}



/***********************************************************************
     * Cache
     * spawn

***********************************************************************/
int ach::Cache::spawn()
{
	return json_object_get_branch_integer(cache, "Current.Checkpoint");
}



/***********************************************************************
     * Cache
     * die

***********************************************************************/
void ach::Cache::die()
{
	deaths++;

	store();
}



/***********************************************************************
     * Cache
     * collect

***********************************************************************/
void ach::Cache::collect(int id)
{
	json_array_append_new(json_object_get(info, "Item"), json_integer(id));

	store();
}



/***********************************************************************
     * Cache
     * checkpoint

***********************************************************************/
void ach::Cache::checkpoint(int id)
{
	json_object_set_branch_integer(cache, "Current.Checkpoint", id);

	store();
}



/***********************************************************************
     * Cache
     * canReturn

***********************************************************************/
bool ach::Cache::canReturn()
{
	return false;
}



/***********************************************************************
     * Cache
     * getPlaytime

***********************************************************************/
sf::String ach::Cache::getPlaytime()
{
	char result[STR_LEN_MENU];

	int ptime = playtime * 1000;
	int msec  = ptime % 1000; ptime /= 1000;
	int sec   = ptime % 60  ; ptime /= 60;
	int min   = ptime % 60  ; ptime /= 60;

	snprintf(result, STR_LEN_MENU, "%d:%02d:%02d.%03d", ptime, min, sec, msec);

	return sf::String(result);
}



/***********************************************************************
     * Cache
     * getDeaths

***********************************************************************/
sf::String ach::Cache::getDeaths()
{
	return sf::String(std::to_string(deaths));
}



/***********************************************************************
     * Cache
     * getDeaths

***********************************************************************/
sf::String ach::Cache::getCollected()
{
	int total     = 0;
	int collected = 0;

	list_foreach(db->map)
	{
		total     += db->map[i]->items;
		collected += json_array_size(json_object_getv_branch(cache, "Map.%s.Item", db->map[i]->name));
	}

	if (!total)
		return sf::String("100%");


	return sf::String(std::to_string((collected * 100) / total)) + "%";
}



/***********************************************************************
     * Cache
     * getDeaths

***********************************************************************/
sf::String ach::Cache::getItems()
{
	if (!current->items)
		return sf::String("100%");


	return sf::String(std::to_string((json_array_size(json_object_get(info, "Item")) * 100) / current->items)) + "%";
}



/***********************************************************************
     * Cache
     * setFlag

***********************************************************************/
void ach::Cache::setFlag(const char *name)
{
	json_object_setv_branch_boolean(cache, true, "Flags.%s", name);
}
