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
     * isReturn

***********************************************************************/
bool ach::Cache::isReturn()
{
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
     * getPlaytime

***********************************************************************/
sf::String ach::Cache::getPlaytime()
{
	return str_time(playtime);
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
     * getCollected

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

	return str_percent(collected, total);
}



/***********************************************************************
     * Cache
     * getItems

***********************************************************************/
sf::String ach::Cache::getItems()
{
	return str_percent(json_array_size(json_object_get(info, "Item")), current->items);
}



/***********************************************************************
     * Cache
     * listLevels

***********************************************************************/
json_t* ach::Cache::listLevels(ach::LevelList list)
{
	json_t *result = json_array();

	switch (list)
	{
		case ach::LevelList::llDream     : listLevelsDream     (result); break;
		case ach::LevelList::llReplay    : listLevelsReplay    (result); break;
		case ach::LevelList::llNavigation: listLevelsNavigation(result); break;
		case ach::LevelList::llTraining  : listLevelsTraining  (result); break;
	}

	return result;
}



/***********************************************************************
     * Cache
     * listLevelsDream

***********************************************************************/
void ach::Cache::listLevelsDream(json_t *list)
{
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(campaign, "Dream"), index, item)
	{
		if (!getFlag(json_object_get_string(item, "Flag")))
			continue;

		if (isBeaten(json_object_get_string(item, "Level")))
			continue;

		json_array_append(list, json_object_get(item, "Level"));
	}
}



/***********************************************************************
     * Cache
     * listLevelsReplay

***********************************************************************/
void ach::Cache::listLevelsReplay(json_t *list)
{
	list_foreach(db->map)
	{
		if (!db->map[i]->replay)
			continue;

		if (!isBeaten(db->map[i]->name))
			continue;

		json_array_append_new(list, json_string(db->map[i]->name));
	}
}



/***********************************************************************
     * Cache
     * listLevelsNavigation

***********************************************************************/
void ach::Cache::listLevelsNavigation(json_t *list)
{
	json_t      *pack;
	json_t      *item;

	size_t      index;
	const char *i;

	json_object_foreach(json_object_get(campaign, "Navigation"), i, pack)
	{
		json_array_foreach(json_object_get(pack, "Levels"), index, item)
			if (!isBeaten(json_string_value(item)))
				json_array_append(list, item);

		if (json_array_size(list))
			break;
	}
}



/***********************************************************************
     * Cache
     * listLevelsTraining

***********************************************************************/
void ach::Cache::listLevelsTraining(json_t *list)
{
	list_foreach(db->map)
		json_array_append_new(list, json_string(db->map[i]->name));
}



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
