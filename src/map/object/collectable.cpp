#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectCollectable
     * constructor

***********************************************************************/
ach::MapObjectCollectable::MapObjectCollectable(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Collect"));

	setSheet(json_object_get_string(obj, "name"));
}



/***********************************************************************
     * MapObjectCollectable
     * destructor

***********************************************************************/
ach::MapObjectCollectable::~MapObjectCollectable()
{
}



/***********************************************************************
     * MapObjectCollectable
     * touch

***********************************************************************/
void ach::MapObjectCollectable::touch()
{
	if (!alive)
		return;

	alive = false;

	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White, MATH_PI / 2.0f, 8));
	sm->play(sfx->snd);
}
