#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDecor
     * constructor

***********************************************************************/
ach::MapObjectDecor::MapObjectDecor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectDecor
     * destructor

***********************************************************************/
ach::MapObjectDecor::~MapObjectDecor()
{
}
