#include "meta/headers.hpp"


/***********************************************************************
     * AIBouncer
     * constructor

***********************************************************************/
ach::AIBouncer::AIBouncer(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
	orient  = dir_orient(initial);
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
	owner->phys.vel = dir_vector_f(dir) * owner->speed;
}



/***********************************************************************
     * AIBouncer
     * reset

***********************************************************************/
void ach::AIBouncer::reset()
{
	dir      = initial;
	grounded = true;

	owner->body->setDirection(dir);
}



/***********************************************************************
     * AIBouncer
     * collide

***********************************************************************/
void ach::AIBouncer::collide(ach::PhysLine*)
{
	dir = !dir;

	owner->body->setDirection(dir);
}
