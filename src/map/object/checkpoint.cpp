#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectCheckpoint
     * constructor

***********************************************************************/
ach::MapObjectCheckpoint::MapObjectCheckpoint(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model  = new ach::Model(db->getModel(json_object_get_branch_string(dm->data, "Data.Game.Meta.GFX.Checkpoint")));
	active = false;

	animate();
}



/***********************************************************************
     * MapObjectCheckpoint
     * destructor

***********************************************************************/
ach::MapObjectCheckpoint::~MapObjectCheckpoint()
{
}



/***********************************************************************
     * MapObjectCheckpoint
     * touch

***********************************************************************/
void ach::MapObjectCheckpoint::touch()
{
	active = true;

	animate();
}



/***********************************************************************
     * MapObjectCheckpoint
     * animate

***********************************************************************/
void ach::MapObjectCheckpoint::animate()
{
	if (active) model->setAnimation("Active"  );
	else        model->setAnimation("Inactive");
}
