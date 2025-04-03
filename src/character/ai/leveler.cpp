#include "meta/headers.hpp"


/***********************************************************************
     * AILeveler
     * constructor

***********************************************************************/
ach::AILeveler::AILeveler(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
}



/***********************************************************************
     * AILeveler
     * destructor

***********************************************************************/
ach::AILeveler::~AILeveler()
{
}



/***********************************************************************
     * AILeveler
     * control

***********************************************************************/
void ach::AILeveler::control()
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
     * AILeveler
     * reset

***********************************************************************/
void ach::AILeveler::reset()
{
	dir = initial;
}



/***********************************************************************
     * AILeveler
     * collide

***********************************************************************/
void ach::AILeveler::collide(ach::PhysLine*)
{
	dir = !dir;
}
