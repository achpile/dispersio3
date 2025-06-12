#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectAntigrav
     * constructor

***********************************************************************/
ach::MapObjectAntigrav::MapObjectAntigrav(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid  = true;
	sfx    = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Antigrav"));

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectAntigrav
     * destructor

***********************************************************************/
ach::MapObjectAntigrav::~MapObjectAntigrav()
{
}



/***********************************************************************
     * MapObjectAntigrav
     * stand

***********************************************************************/
void ach::MapObjectAntigrav::stand(ach::Phys*)
{
	sm->play(sfx->snd);
}
