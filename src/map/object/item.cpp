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

	blinking.set(0.7f);
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
     * reset

***********************************************************************/
void ach::MapObjectItem::reset()
{
	blinking.reset();
}



/***********************************************************************
     * MapObjectItem
     * handle

***********************************************************************/
void ach::MapObjectItem::handle()
{
	if (!blinking.update())
		blinking.reset();

	if (blinking.value < 0.1f) model->shader = ach::RenderShader::rsWhite;
	else                       model->shader = ach::RenderShader::rsNone;
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
	cache->setFlag(base->flag);
	cache->collect(id, false);
	sm->play(sfx->snd);
}
