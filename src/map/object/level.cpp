#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectLevel
     * constructor

***********************************************************************/
ach::MapObjectLevel::MapObjectLevel(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	type = pair_get_enum(json_property_get_string(obj, "Type"), pairLevelMode);

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectLevel
     * destructor

***********************************************************************/
ach::MapObjectLevel::~MapObjectLevel()
{
}



/***********************************************************************
     * MapObjectLevel
     * touch

***********************************************************************/
void ach::MapObjectLevel::touch()
{
	select();
}



/***********************************************************************
     * MapObjectLevel
     * use

***********************************************************************/
void ach::MapObjectLevel::use()
{
	if (cache->isPossible(type)) world->select(type);
	else                         world->notify(cache->getError(type));
}
