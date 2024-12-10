#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDoor
     * constructor

***********************************************************************/
ach::MapObjectDoor::MapObjectDoor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
	id    = json_property_get_integer(obj, "id");
	pair  = NULL;
}



/***********************************************************************
     * MapObjectDoor
     * destructor

***********************************************************************/
ach::MapObjectDoor::~MapObjectDoor()
{
}



/***********************************************************************
     * MapObjectDoor
     * connect

***********************************************************************/
void ach::MapObjectDoor::connect(ach::MapObjectDoor *_pair)
{
	if (pair)
		return;

	if (id != _pair->id)
		return;

	pair = _pair;
	pair->connect(this);
}
