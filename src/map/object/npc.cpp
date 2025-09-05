#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectNPC
     * constructor

***********************************************************************/
ach::MapObjectNPC::MapObjectNPC(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	base  = db->getNPC(json_object_get_string(obj, "name"));
	face  = pair_get_enum(json_property_get_string(obj, "Face"), pairDirection);

	setModel(base->model);

	spawn = phys.pos;

	model->setAnimation("Idle");
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
	phys.pos       = spawn;
	model->scale.x = dir_sign(face);
}



/***********************************************************************
     * MapObjectNPC
     * touch

***********************************************************************/
void ach::MapObjectNPC::touch()
{
	select();
}
