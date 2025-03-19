#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectBreak
     * constructor

***********************************************************************/
ach::MapObjectBreak::MapObjectBreak(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid   = true;
	sfx     = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Break"));
	crack   = new ach::Model(db->getSheet(json_object_get_branch_string(dm->data, "Data.Game.Meta.GFX.Crack")));
	respawn = json_property_get_boolean(obj, "Respawn");

	cracking.set(GAME_FRAGILE_BREAKING);

	setSheet(json_object_get_string(obj, "name"));

	crack->anim.loop = false;
	crack->setScale(phys.size);
}



/***********************************************************************
     * MapObjectBreak
     * destructor

***********************************************************************/
ach::MapObjectBreak::~MapObjectBreak()
{
	delete crack;
}



/***********************************************************************
     * MapObjectBreak
     * reset

***********************************************************************/
void ach::MapObjectBreak::reset()
{
	if (!alive && !respawn)
		return;

	alive   = true;
	cracked = false;

	cracking.reset();
	crack->anim.reset();
}



/***********************************************************************
     * MapObjectBreak
     * handle

***********************************************************************/
void ach::MapObjectBreak::handle()
{
	if (!cracked)
		return;

	if (!cracking.update() && alive)
	{
		alive = false;
		sm->play(sfx->snd);

		world->map->gfx.push_back(new ach::EffectBreak(phys.pos, model->sheet->getFrame(model->anim.frame)));
	}
}



/***********************************************************************
     * MapObjectBreak
     * post

***********************************************************************/
void ach::MapObjectBreak::post()
{
	if (!cracked)
		return;

	crack->update();
	crack->render(phys.pos);
}



/***********************************************************************
     * MapObjectBreak
     * hit

***********************************************************************/
void ach::MapObjectBreak::hit()
{
	if (cracked)
		return;

	cracked = true;
}
