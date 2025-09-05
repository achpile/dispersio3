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
	alive = true;
	id    = json_object_get_integer(obj, "id");

	phys.init(vector_json_rect(obj));

	lines.push_back(new ach::PhysLine(this));
	lines.push_back(new ach::PhysLine(this));
	lines.push_back(new ach::PhysLine(this));
	lines.push_back(new ach::PhysLine(this));

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
	if (!alive)
		return true;

	if (!visible(true))
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

	if (!visible(false))
		return;

	if (model)
		model->render(phys.pos);

	post();
}



/***********************************************************************
     * MapObject
     * visible

***********************************************************************/
bool ach::MapObject::visible(bool area)
{
	return world->map->cam->check(phys.rect, area);
}



/***********************************************************************
     * MapObject
     * process

***********************************************************************/
void ach::MapObject::process()
{
	if (!visible(true))
		return;

	handle();
	box();
}



/***********************************************************************
     * MapObject
     * select

***********************************************************************/
void ach::MapObject::select()
{
	world->map->selector->object = &phys;
}



/***********************************************************************
     * MapObject
     * box

***********************************************************************/
void ach::MapObject::box()
{
	if (!solid)
		return;

	if (!alive)
		return;

	lines[0]->set(rect_lt(phys.rect), rect_rt(phys.rect));
	lines[1]->set(rect_rt(phys.rect), rect_rb(phys.rect));
	lines[2]->set(rect_rb(phys.rect), rect_lb(phys.rect));
	lines[3]->set(rect_lb(phys.rect), rect_lt(phys.rect));

	list_foreach(lines)
		world->map->solids.push_back(lines[i]);
}



/***********************************************************************
     * MapObject
     * setModel

***********************************************************************/
void ach::MapObject::setModel(ach::DataModel *_model)
{
	if (model)
		delete model;

	model = new ach::Model(_model);

	phys.resize(model->sheet->size);
}



/***********************************************************************
     * MapObject
     * setModel

***********************************************************************/
void ach::MapObject::setModel(const char *_model)
{
	setModel(db->getModel(_model));
}



/***********************************************************************
     * MapObject
     * setSheet

***********************************************************************/
void ach::MapObject::setSheet(const char *_sheet)
{
	if (model)
		delete model;

	model = new ach::Model(db->getSheet(_sheet));

	phys.resize(model->sheet->size);
}
