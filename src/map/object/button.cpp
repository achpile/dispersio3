#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectButton
     * constructor

***********************************************************************/
ach::MapObjectButton::MapObjectButton(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	boss    = NULL;
	sfx     = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Button"));
	link    = json_property_get_integer(obj, "Boss");

	blinking.set(0.7f);

	if (!link)
		logger->log(ach::LogLevel::llError, "Orphaned button ID#%d", id);

	setModel(json_object_get_string(obj, "name"));

	animate();
}



/***********************************************************************
     * MapObjectButton
     * destructor

***********************************************************************/
ach::MapObjectButton::~MapObjectButton()
{
}



/***********************************************************************
     * MapObjectButton
     * reset

***********************************************************************/
void ach::MapObjectButton::reset()
{
	active  = false;
	pressed = false;

	blinking.reset();
	animate();
}



/***********************************************************************
     * MapObjectButton
     * handle

***********************************************************************/
void ach::MapObjectButton::handle()
{
	if (active && !pressed)
	{
		if (!blinking.update())
			blinking.reset();

		if (blinking.value < 0.1f) model->shader = ach::RenderShader::rsWhite;
		else                       model->shader = ach::RenderShader::rsNone;
	}
	else
	{
		model->shader = ach::RenderShader::rsNone;
	}
}



/***********************************************************************
     * MapObjectButton
     * init

***********************************************************************/
void ach::MapObjectButton::init(ach::Map *map)
{
	if (link)
		boss = map->findMapBoss(link);

	if (boss)
		boss->buttons.push_back(this);
}



/***********************************************************************
     * MapObjectButton
     * touch

***********************************************************************/
void ach::MapObjectButton::touch()
{
	if (!active)
		return;

	if (pressed)
		return;

	pressed = true;

	if (boss)
		boss->press();

	sm->play(sfx->snd);
	animate();
}



/***********************************************************************
     * MapObjectButton
     * activate

***********************************************************************/
void ach::MapObjectButton::activate()
{
	active = true;

	animate();
}



/***********************************************************************
     * MapObjectButton
     * animate

***********************************************************************/
void ach::MapObjectButton::animate()
{
	if (!active)
		model->setAnimation("Inactive");
	else if (pressed)
		model->setAnimation("Pressed");
	else
		model->setAnimation("Idle");
}
