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

	lines.push_back(new ach::PhysLine());
	lines.push_back(new ach::PhysLine());
	lines.push_back(new ach::PhysLine());
	lines.push_back(new ach::PhysLine());

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

	list_delete(lines);
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

	handle();

	if (solid)
		box();
}



/***********************************************************************
     * MapObject
     * box

***********************************************************************/
void ach::MapObject::box()
{
	lines[0]->set(rect_lt(phys.rect), rect_rt(phys.rect));
	lines[1]->set(rect_rt(phys.rect), rect_rb(phys.rect));
	lines[2]->set(rect_rb(phys.rect), rect_lb(phys.rect));
	lines[3]->set(rect_lb(phys.rect), rect_lt(phys.rect));

	list_foreach(lines)
		world->map->solids.push_back(lines[i]);
}



/***********************************************************************
     * MapObject
     * reset

***********************************************************************/
void ach::MapObject::reset()
{
	alive = true;
}
