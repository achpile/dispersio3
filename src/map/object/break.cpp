#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectBreak
     * constructor

***********************************************************************/
ach::MapObjectBreak::MapObjectBreak(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid  = true;
	sfx    = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Break"));
	crack  = new ach::Model(db->getSheet(json_object_get_branch_string(dm->data, "Data.Game.Meta.GFX.Crack")));
	secret = json_property_get_boolean(obj, "Secret");

	cracking.set(GAME_FRAGILE_BREAKING);

	setSheet(json_object_get_string(obj, "name"));

	crack->anim.loop = false;
	crack->setScale(phys.size);

	crack->layer = ach::RenderLayer::rlFront;
	model->layer = ach::RenderLayer::rlFront;
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
	if (!alive && secret)
		return;

	alive   = true;
	cracked = false;

	cracking.reset();
	crack->anim.reset();

	if (!secret)
		crack->anim.frame = (crack->anim.end - crack->anim.start) / 5;
}



/***********************************************************************
     * MapObjectBreak
     * handle

***********************************************************************/
void ach::MapObjectBreak::handle()
{
	if (!cracked)
		return;

	crack->update();

	if (!cracking.update() && alive)
	{
		alive = false;
		sm->play(sfx->snd);

		world->map->gfx.push_back(new ach::EffectBreak(phys.pos, model->sheet->getFrame(model->anim.frame), 0.25f, 100.0f));
	}
}



/***********************************************************************
     * MapObjectBreak
     * post

***********************************************************************/
void ach::MapObjectBreak::post()
{
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
