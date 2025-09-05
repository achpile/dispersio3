#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectNPC
     * constructor

***********************************************************************/
ach::MapObjectNPC::MapObjectNPC(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	base  = db->getNPC(json_object_get_string(obj, "name"));
	face  = pair_get_enum(json_property_get_string(obj, "Face"), pairDirection);

	min   = rect_value(phys.rect, ach::Direction::dLeft );
	max   = rect_value(phys.rect, ach::Direction::dRight);

	setModel(base->model);

	spawn  = phys.pos;
	min   += phys.rect.width / 2.0f;
	max   -= phys.rect.width / 2.0f;
}



/***********************************************************************
     * MapObjectNPC
     * destructor

***********************************************************************/
ach::MapObjectNPC::~MapObjectNPC()
{
}



/***********************************************************************
     * MapObjectNPC
     * reset

***********************************************************************/
void ach::MapObjectNPC::reset()
{
	walking        = false;
	phys.pos       = spawn;
	model->scale.x = dir_sign(face);

	model->setAnimation("Idle");
}



/***********************************************************************
     * MapObjectNPC
     * touch

***********************************************************************/
void ach::MapObjectNPC::touch()
{
	select();
}
