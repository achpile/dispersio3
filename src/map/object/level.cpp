#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectLevel
     * constructor

***********************************************************************/
ach::MapObjectLevel::MapObjectLevel(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	type = pair_get_enum(json_property_get_string(obj, "Type"), pairLevelList);

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
	world->select(type);
}
