#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectNPC
     * constructor

***********************************************************************/
ach::MapObjectNPC::MapObjectNPC(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	base = db->getNPC(json_object_get_string(obj, "name"));

	setModel(base->model);

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
     * touch

***********************************************************************/
void ach::MapObjectNPC::touch()
{
	select();
}
