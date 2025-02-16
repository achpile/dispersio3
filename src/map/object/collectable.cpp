#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectCollectable
     * constructor

***********************************************************************/
ach::MapObjectCollectable::MapObjectCollectable(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getSheet(json_object_get_string(obj, "name")));
}



/***********************************************************************
     * MapObjectCollectable
     * destructor

***********************************************************************/
ach::MapObjectCollectable::~MapObjectCollectable()
{
}
