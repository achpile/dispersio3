#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectCheckpoint
     * constructor

***********************************************************************/
ach::MapObjectCheckpoint::MapObjectCheckpoint(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Checkpoint"));

	setModel(json_object_get_branch_string(dm->data, "Data.Game.Meta.GFX.Checkpoint"));

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

	world->player->spawn = rect_place(phys.rect, world->player->phys.rect);
	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White, MATH_PI / 2.0f, 8));

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
	int   offset;
	float value;

	offset = model->anim.frame - model->anim.start;
	value  = model->anim.framer.value;

	if (active) model->setAnimation("Active"  );
	else        model->setAnimation("Inactive");

	model->anim.frame = model->anim.start + offset;
	model->anim.framer.value = value;
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
