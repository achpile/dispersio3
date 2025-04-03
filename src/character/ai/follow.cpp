#include "meta/headers.hpp"


/***********************************************************************
     * AIFollow
     * constructor

***********************************************************************/
ach::AIFollow::AIFollow(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
}



/***********************************************************************
     * AIFollow
     * destructor

***********************************************************************/
ach::AIFollow::~AIFollow()
{
}



/***********************************************************************
     * AIFollow
     * control

***********************************************************************/
void ach::AIFollow::control()
{
	if (dir_orient(dir) == ach::Orientation::oHorizontal)
		owner->dir.x = dir_sign(dir);
	else
	{
		search();

		if (target)
			owner->dir.x = math_sign(target->phys.pos.x - owner->phys.pos.x);
	}

	owner->phys.vel = dir_vector_f(dir) * owner->speed;
}



/***********************************************************************
     * AIFollow
     * reset

***********************************************************************/
void ach::AIFollow::reset()
{
	dir = initial;
}



/***********************************************************************
     * AIFollow
     * collide

***********************************************************************/
void ach::AIFollow::collide(ach::PhysLine*)
{
	dir = !dir;
}
