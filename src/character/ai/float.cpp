#include "meta/headers.hpp"


/***********************************************************************
     * AIFloat
     * constructor

***********************************************************************/
ach::AIFloat::AIFloat(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
}



/***********************************************************************
     * AIFloat
     * destructor

***********************************************************************/
ach::AIFloat::~AIFloat()
{
}



/***********************************************************************
     * AIFloat
     * control

***********************************************************************/
void ach::AIFloat::control()
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
     * AIFloat
     * reset

***********************************************************************/
void ach::AIFloat::reset()
{
	dir = initial;
}



/***********************************************************************
     * AIFloat
     * collide

***********************************************************************/
void ach::AIFloat::collide(ach::PhysLine*)
{
	dir = !dir;
}
