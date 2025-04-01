#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectDecor
     * constructor

***********************************************************************/
ach::MapObjectDecor::MapObjectDecor(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	setSheet(json_object_get_string(obj, "name"));

	if (json_property_get_boolean(obj, "FlipX"))
		model->scale.x = -1.0f;

	if (json_property_get_boolean(obj, "FlipY"))
		model->scale.y = -1.0f;

	if (json_property_get_boolean(obj, "Foreground"))
		model->layer = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectDecor
     * destructor

***********************************************************************/
ach::MapObjectDecor::~MapObjectDecor()
{
}
