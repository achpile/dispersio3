#include "meta/headers.hpp"


/***********************************************************************
     * MapObject
     * constructor

***********************************************************************/
ach::MapObject::MapObject(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
	model = NULL;
	solid = false;
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
     * process

***********************************************************************/
void ach::MapObject::process()
{
	if (!visible())
		return;

	// TODO: self-process

	// TODO: if solid - recalculate lines and add to map solid lines
}



/***********************************************************************
     * MapObject
     * reset

***********************************************************************/
void ach::MapObject::reset()
{
	alive = true;
}
