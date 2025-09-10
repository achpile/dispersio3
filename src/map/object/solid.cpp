#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectSolid
     * constructor

***********************************************************************/
ach::MapObjectSolid::MapObjectSolid(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid  = true;

	setSheet(json_object_get_string(obj, "name"));

	model->layer = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectSolid
     * destructor

***********************************************************************/
ach::MapObjectSolid::~MapObjectSolid()
{
}
