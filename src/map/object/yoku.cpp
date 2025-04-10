#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectYoku
     * constructor

***********************************************************************/
ach::MapObjectYoku::MapObjectYoku(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	duration = json_property_get_real(obj, "Duration");
	cooldown = json_property_get_real(obj, "Cooldown");
	offset   = json_property_get_real(obj, "Offset"  );

	sfx      = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Yoku"));

	setSheet(json_object_get_string(obj, "name"));

	model->anim.loop = false;
	model->layer     = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectYoku
     * destructor

***********************************************************************/
ach::MapObjectYoku::~MapObjectYoku()
{
}



/***********************************************************************
     * MapObjectYoku
     * reset

***********************************************************************/
void ach::MapObjectYoku::reset()
{
	alive = offset < 0.0f;

	state();

	timer.value = fabs(offset);

	if (alive)
		model->anim.frame = model->anim.end;
}



/***********************************************************************
     * MapObjectYoku
     * handle

***********************************************************************/
void ach::MapObjectYoku::handle()
{
	if (!timer.update())
		return;

	alive = !alive;

	state();

	if (alive)
	{
		model->anim.reset();
		sm->play(sfx->snd);
	}
}



/***********************************************************************
     * MapObjectYoku
     * state

***********************************************************************/
void ach::MapObjectYoku::state()
{
	timer.set(alive ? duration : cooldown);

	solid = alive;
}
