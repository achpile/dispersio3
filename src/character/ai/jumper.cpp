#include "meta/headers.hpp"


/***********************************************************************
     * AIJumper
     * constructor

***********************************************************************/
ach::AIJumper::AIJumper(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	dir = 0;

	cooldown.set(1.0f);
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
		return;

	if (!owner->phys.grounded)
		move();
	else
		dir = math_sign(target->phys.pos.x - owner->phys.pos.x);

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
