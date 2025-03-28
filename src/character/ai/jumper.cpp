#include "meta/headers.hpp"


/***********************************************************************
     * AIJumper
     * constructor

***********************************************************************/
ach::AIJumper::AIJumper(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	dir = 0;

	cooldown.set(json_class_get_real(obj, "Jumping", "Cooldown"));
}



/***********************************************************************
     * AIJumper
     * destructor

***********************************************************************/
ach::AIJumper::~AIJumper()
{
}



/***********************************************************************
     * AIJumper
     * control

***********************************************************************/
void ach::AIJumper::control()
{
	ground();
	search();

	if (owner->phys.grounded)
		cooldown.update();
	else
		cooldown.reset();

	owner->phys.vel.x    = 0.0f;
	owner->phys.moving   = false;

	if (!target)
	{
		cooldown.reset();
		return;
	}

	if (owner->phys.grounded || owner->phys.bounce)
		dir = math_sign(target->phys.pos.x - owner->phys.pos.x);

	if (!owner->phys.grounded)
		move();

	if (!cooldown.isActive())
		jump();
}



/***********************************************************************
     * AIJumper
     * reset

***********************************************************************/
void ach::AIJumper::reset()
{
	cooldown.reset();
}



/***********************************************************************
     * AIJumper
     * move

***********************************************************************/
void ach::AIJumper::move()
{
	if (!dir)
		return;

	owner->dir.x = dir;
	owner->move(dir);
}



/***********************************************************************
     * AIJumper
     * jump

***********************************************************************/
void ach::AIJumper::jump()
{
	owner->jump();
}
