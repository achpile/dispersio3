#include "meta/headers.hpp"


/***********************************************************************
     * MapObject
     * constructor

***********************************************************************/
ach::MapObject::MapObject(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
	model = NULL;
	id    = json_object_get_integer(obj, "id");

	phys.init(vector_json_rect(obj));

	reset();
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
	if (!visible())
		return true;

	if (model)
		model->update();

	return true;
}



/***********************************************************************
     * MapObject
     * render

***********************************************************************/
void ach::MapObject::render()
{
	if (!alive)
		return;

	if (!visible())
		return;

	if (model)
		model->render(phys.pos);
}



/***********************************************************************
     * MapObject
     * visible

***********************************************************************/
bool ach::MapObject::visible()
{
	return world->map->cam->check(phys.rect);
}



/***********************************************************************
     * MapObject
     * reset

***********************************************************************/
void ach::MapObject::reset()
{
	alive = true;
}
