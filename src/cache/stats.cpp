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
