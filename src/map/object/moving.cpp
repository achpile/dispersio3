#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectMoving
     * constructor

***********************************************************************/
ach::MapObjectMoving::MapObjectMoving(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
}



/***********************************************************************
     * MapObjectMoving
     * destructor

***********************************************************************/
ach::MapObjectMoving::~MapObjectMoving()
{
}
