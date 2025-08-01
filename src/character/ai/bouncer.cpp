#include "meta/headers.hpp"


/***********************************************************************
     * AIBouncer
     * constructor

***********************************************************************/
ach::AIBouncer::AIBouncer(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
	orient  = dir_orient(initial);

	cooldown.set(0.5f);
}



/***********************************************************************
     * AIBouncer
     * destructor

***********************************************************************/
ach::AIBouncer::~AIBouncer()
{
}



/***********************************************************************
     * AIBouncer
     * control

***********************************************************************/
void ach::AIBouncer::control()
{
	if (!grounded)
	{
		owner->phys.vel = dir_vector_f(dir) * owner->speed;
		return;
	}

	if (cooldown.update())
		return;

	search();

	if (!target)
		return;

	if (!target->alive)
		return;

	if (fabs(orient_v_coord(!orient, target->phys.pos - owner->phys.pos)) < range)
	{
		sm->play(owner->base->sndJump->snd);
		grounded = false;
	}
}



/***********************************************************************
     * AIBouncer
     * reset

***********************************************************************/
void ach::AIBouncer::reset()
{
	dir      = initial;
	grounded = true;
	range    = 1.5f * vector_len(owner->phys.size);

	cooldown.zero();
	owner->body->setDirection(dir);
}



/***********************************************************************
     * AIBouncer
     * collide

***********************************************************************/
void ach::AIBouncer::collide(ach::PhysLine*)
{
	dir      = !dir;
	grounded = true;

	cooldown.reset();
	sm->play(owner->base->sndLand->snd);

	owner->phys.vel = sf::Vector2f(0.0f, 0.0f);
	owner->body->setDirection(dir);
}
