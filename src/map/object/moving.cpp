#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectMoving
     * constructor

***********************************************************************/
ach::MapObjectMoving::MapObjectMoving(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectMoving
     * destructor

***********************************************************************/
ach::MapObjectMoving::~MapObjectMoving()
{
}



/***********************************************************************
     * MapObjectMoving
     * reset

***********************************************************************/
void ach::MapObjectMoving::reset()
{
}



/***********************************************************************
     * MapObjectMoving
     * handle

***********************************************************************/
void ach::MapObjectMoving::handle()
{
}
