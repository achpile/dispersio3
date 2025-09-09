#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectGate
     * constructor

***********************************************************************/
ach::MapObjectGate::MapObjectGate(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid  = true;
	sfx    = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Break"));

	setSheet(json_object_get_string(obj, "name"));

	model->layer = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectGate
     * destructor

***********************************************************************/
ach::MapObjectGate::~MapObjectGate()
{
}



/***********************************************************************
     * MapObjectGate
     * reset

***********************************************************************/
void ach::MapObjectGate::reset()
{
	hidden = true;
}



/***********************************************************************
     * MapObjectGate
     * close

***********************************************************************/
void ach::MapObjectGate::close()
{
	if (!hidden)
		return;

	hidden = false;

	sm->play(sfx->snd);
}
