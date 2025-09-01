#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectPoints
     * constructor

***********************************************************************/
ach::MapObjectPoints::MapObjectPoints(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Collect"));

	blinking.set(0.7f);

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectPoints
     * destructor

***********************************************************************/
ach::MapObjectPoints::~MapObjectPoints()
{
}



/***********************************************************************
     * MapObjectPoints
     * reset

***********************************************************************/
void ach::MapObjectPoints::reset()
{
	blinking.reset();
}



/***********************************************************************
     * MapObjectPoints
     * handle

***********************************************************************/
void ach::MapObjectPoints::handle()
{
	if (!blinking.update())
		blinking.reset();

	if (blinking.value < 0.1f) model->state = rm->states.white;
	else                       model->state = rm->states.none;
}



/***********************************************************************
     * MapObjectPoints
     * touch

***********************************************************************/
void ach::MapObjectPoints::touch()
{
	if (!alive)
		return;

	alive = false;

	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White, MATH_PI / 2.0f, 8));
	cache->collect(id);
	sm->play(sfx->snd);
}
