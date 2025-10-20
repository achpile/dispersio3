#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * die

***********************************************************************/
void ach::Cache::die()
{
	deaths++;

	save();
}



/***********************************************************************
     * Cache
     * collect

***********************************************************************/
void ach::Cache::collect(int id, bool money)
{
	json_array_append_new(json_object_get(info, "Item"), json_integer(id));

	if (money)
	{
		cash++;

		if (isMoneyCollected())
			setFlag("HasMoney");
	}

	achieve();
	save();
}



/***********************************************************************
     * Cache
     * checkpoint

***********************************************************************/
void ach::Cache::checkpoint(int id)
{
	json_object_set_branch_integer(cache, "Current.Checkpoint", id);

	save();
}



/***********************************************************************
     * Cache
     * beat

***********************************************************************/
void ach::Cache::beat(const char *map)
{
	char flag[STR_LEN_NAME];

	snprintf(flag, STR_LEN_NAME, "Beaten%s", map);

	setFlag(flag);
}



/***********************************************************************
     * Cache
     * achieve

***********************************************************************/
void ach::Cache::achieve()
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

	if (collected == total)
		records->setAchievement(ach::Achievement::acCollectAll);

	items(ach::ItemCategory::icFreshener, ach::Achievement::acCollectFresh);
	items(ach::ItemCategory::icGame     , ach::Achievement::acCollectGames);
}



/***********************************************************************
     * Cache
     * items

***********************************************************************/
void ach::Cache::items(ach::ItemCategory category, ach::Achievement achievement)
{
	list_foreach(db->item)
	{
		if (db->item[i]->category != category)
			continue;

		if (!getFlag(db->item[i]->flag))
			return;
	}

	records->setAchievement(achievement);
}
