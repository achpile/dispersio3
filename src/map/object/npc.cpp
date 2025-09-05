#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectNPC
     * constructor

***********************************************************************/
ach::MapObjectNPC::MapObjectNPC(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	base  = db->getNPC(json_object_get_string(obj, "name"));
	face  = pair_get_enum(json_property_get_string(obj, "Face"), pairDirection);

	min   = rect_value(phys.rect, ach::Direction::dLeft );
	max   = rect_value(phys.rect, ach::Direction::dRight);

	setModel(base->model);

	spawn  = phys.pos;
	min   += phys.rect.width / 2.0f;
	max   -= phys.rect.width / 2.0f;
}



/***********************************************************************
     * MapObjectNPC
     * destructor

***********************************************************************/
ach::MapObjectNPC::~MapObjectNPC()
{
}



/***********************************************************************
     * MapObjectNPC
     * reset

***********************************************************************/
void ach::MapObjectNPC::reset()
{
	phys.pos       = spawn;
	model->scale.x = dir_sign(face);

	stop();
}



/***********************************************************************
     * MapObjectNPC
     * handle

***********************************************************************/
void ach::MapObjectNPC::handle()
{
	if (!base->wander)
		return;

	if (walking)
	{
		phys.update();

		if ((phys.vel.x < 0.0f && phys.pos.x <= dest) || (phys.vel.x > 0.0f && phys.pos.x >= dest))
		{
			phys.pos.x = dest;
			stop();
		}
	}
	else
	{
		if (!wait.update())
			move();
	}
}



/***********************************************************************
     * MapObjectNPC
     * touch

***********************************************************************/
void ach::MapObjectNPC::touch()
{
	select();
}



/***********************************************************************
     * MapObjectNPC
     * use

***********************************************************************/
void ach::MapObjectNPC::use()
{
}



/***********************************************************************
     * MapObjectNPC
     * move

***********************************************************************/
void ach::MapObjectNPC::move()
{
	dest = random_float(min, max);

	if (fabs(dest - phys.pos.x) < 16.0f)
		move();

	walking    = true;
	phys.vel.x = math_sign(dest - phys.pos.x) * base->speed;

	model->setAnimation("Moving");
	model->scale.x = math_sign(phys.vel.x);
}



/***********************************************************************
     * MapObjectNPC
     * stop

***********************************************************************/
void ach::MapObjectNPC::stop()
{
	walking    = false;
	phys.vel.x = 0.0f;

	model->setAnimation("Idle");
	wait.set(random_float(3.0f, 5.0f));
}
