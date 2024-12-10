#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDoor
     * constructor

***********************************************************************/
ach::MapObjectDoor::MapObjectDoor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
	pair  = json_property_get_integer(obj, "pair");
}



/***********************************************************************
     * MapObjectDoor
     * destructor

***********************************************************************/
ach::MapObjectDoor::~MapObjectDoor()
{
}
