#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectButton
     * constructor

***********************************************************************/
ach::MapObjectButton::MapObjectButton(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	active  = true;
	pressed = false;

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
     * touch

***********************************************************************/
void ach::MapObjectButton::touch()
{
	if (!active)
		return;

	if (pressed)
		return;

	pressed = true;

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
