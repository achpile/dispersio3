#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * listLevels

***********************************************************************/
json_t* ach::Cache::listLevels(ach::LevelMode list)
{
	json_t *result = json_array();

	switch (list)
	{
		case ach::LevelMode::lmDream     : listLevelsDream     (result); break;
		case ach::LevelMode::lmReplay    : listLevelsReplay    (result); break;
		case ach::LevelMode::lmNavigation: listLevelsNavigation(result); break;
		case ach::LevelMode::lmTraining  : listLevelsTraining  (result); break;
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
	ach::DataMap *map;

	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(campaign, "MapList"), index, item)
	{
		map = db->getMap(json_string_value(item));

		if (!map->replay)
			continue;

		if (!isBeaten(json_string_value(item)))
			continue;

		json_array_append(list, item);
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
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(campaign, "MapList"), index, item)
		if (!db->getMap(json_string_value(item))->achievement || records->getAchievement(pair_get_enum(json_string_value(item), pairAchievement)))
			json_array_append(list, item);
}
