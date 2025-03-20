#include "meta/headers.hpp"


/***********************************************************************
     * AICannon
     * constructor

***********************************************************************/
ach::AICannon::AICannon(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial  = pair_get_enum(json_class_get_string(obj, "Moving"  , "Direction"), pairDirection);
	aim      = pair_get_enum(json_class_get_string(obj, "Shooting", "Aim"      ), pairDirection);
	cooldown = json_class_get_real(obj, "Shooting", "Cooldown");
	offset   = json_class_get_real(obj, "Shooting", "Offset"  );
}



/***********************************************************************
     * AICannon
     * destructor

***********************************************************************/
ach::AICannon::~AICannon()
{
}



/***********************************************************************
     * AICannon
     * control

***********************************************************************/
void ach::AICannon::control()
{
	owner->phys.vel = dir_vector_f(dir) * owner->speed;
}



/***********************************************************************
     * AICannon
     * reset

***********************************************************************/
void ach::AICannon::reset()
{
	dir = initial;

	owner->aim = dir_vector_f(aim);
	owner->body->setDirection(aim);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}



/***********************************************************************
     * AICannon
     * collide

***********************************************************************/
void ach::AICannon::collide(ach::PhysLine*)
{
	dir = !dir;
}
