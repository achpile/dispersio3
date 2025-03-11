#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectGoal
     * constructor

***********************************************************************/
ach::MapObjectGoal::MapObjectGoal(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Goal"));
}



/***********************************************************************
     * MapObjectGoal
     * destructor

***********************************************************************/
ach::MapObjectGoal::~MapObjectGoal()
{
}



/***********************************************************************
     * MapObjectGoal
     * touch

***********************************************************************/
void ach::MapObjectGoal::touch()
{
	sm->play(sfx->snd);
	world->goal();
}
