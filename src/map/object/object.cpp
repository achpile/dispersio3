#include "meta/headers.hpp"


/***********************************************************************
     * MapObject
     * constructor

***********************************************************************/
ach::MapObject::MapObject(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
	model = NULL;
	alive = true;
	id    = json_object_get_integer(obj, "id");

	phys.init(vector_json_rect(obj));
}



/***********************************************************************
     * MapObject
     * destructor

***********************************************************************/
ach::MapObject::~MapObject()
{
	if (model)
		delete model;
}



/***********************************************************************
     * MapObject
     * update

***********************************************************************/
bool ach::MapObject::update()
{
	if (model)
		model->update();

	return alive;
}



/***********************************************************************
     * MapObject
     * render

***********************************************************************/
void ach::MapObject::render()
{
	if (model)
		model->render(phys.pos);
}
