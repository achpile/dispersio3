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
     * init

***********************************************************************/
void ach::MapObjectCheckpoint::init(ach::Map *map)
{
	map->checkpoints.push_back(this);
}



/***********************************************************************
     * MapObjectCheckpoint
     * touch

***********************************************************************/
void ach::MapObjectCheckpoint::touch()
{
	active = true;

	world->player->spawn = phys.pos;

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
