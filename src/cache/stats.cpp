#include "meta/headers.hpp"


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

	ach::DataMap *map;

	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(campaign, "MapList"), index, item)
	{
		map        = db->getMap(json_string_value(item));
		total     += map->items;
		collected += json_array_size(json_object_getv_branch(cache, "Map.%s.Item", map->name));
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
     * getItems

***********************************************************************/
sf::String ach::Cache::getItems(const char *name)
{
	ach::DataMap *map = db->getMap(name);

	return str_percent(json_array_size(json_object_getv_branch(cache, "Map.%s.Item", name)), map->items);
}
