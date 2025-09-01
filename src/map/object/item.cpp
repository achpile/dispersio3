#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectItem
     * constructor

***********************************************************************/
ach::MapObjectItem::MapObjectItem(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	base  = db->getItem(json_object_get_string(obj, "name"));
	sfx   = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Collect"));

	model = new ach::Model(base->sheet);

	phys.resize(model->sheet->size);
}



/***********************************************************************
     * MapObjectItem
     * destructor

***********************************************************************/
ach::MapObjectItem::~MapObjectItem()
{
}



/***********************************************************************
     * MapObjectItem
     * touch

***********************************************************************/
void ach::MapObjectItem::touch()
{
	if (!alive)
		return;

	alive = false;

	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White, MATH_PI / 2.0f, 8));
	cache->collect(id);
	cache->setFlag(base->flag);
	sm->play(sfx->snd);
}
