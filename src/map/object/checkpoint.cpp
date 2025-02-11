#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectCheckpoint
     * constructor

***********************************************************************/
ach::MapObjectCheckpoint::MapObjectCheckpoint(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	model = new ach::Model(db->getModel(json_object_get_branch_string(dm->data, "Data.Game.Meta.GFX.Checkpoint")));
	sfx   = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Checkpoint"));

	deactivate();
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
	if (active)
		return;

	list_foreach(world->map->checkpoints)
		world->map->checkpoints[i]->deactivate();

	world->player->spawn = phys.pos;
	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White));

	active = true;
	animate();

	sm->play(sfx->snd);
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



/***********************************************************************
     * MapObjectCheckpoint
     * deactivate

***********************************************************************/
void ach::MapObjectCheckpoint::deactivate()
{
	active = false;
	animate();
}
