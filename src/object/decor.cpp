#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDecor
     * constructor

***********************************************************************/
ach::MapObjectDecor::MapObjectDecor(json_t *obj) : MapObject(obj)
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
