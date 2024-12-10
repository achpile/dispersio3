#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDecor
     * constructor

***********************************************************************/
ach::MapObjectDecor::MapObjectDecor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
}



/***********************************************************************
     * MapObjectDecor
     * destructor

***********************************************************************/
ach::MapObjectDecor::~MapObjectDecor()
{
}
