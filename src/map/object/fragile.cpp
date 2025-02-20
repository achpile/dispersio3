#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectFragile
     * constructor

***********************************************************************/
ach::MapObjectFragile::MapObjectFragile(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectFragile
     * destructor

***********************************************************************/
ach::MapObjectFragile::~MapObjectFragile()
{
}
