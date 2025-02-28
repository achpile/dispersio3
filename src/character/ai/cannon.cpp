#include "meta/headers.hpp"


/***********************************************************************
     * AICannon
     * constructor

***********************************************************************/
ach::AICannon::AICannon(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	dir      = pair_get_enum(json_class_get_string(obj, "Shooting", "Aim"), pairDirection);
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
     * reset

***********************************************************************/
void ach::AICannon::reset()
{
	owner->aim = dir_vector_f(dir);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}



/***********************************************************************
     * AICannon
     * collide

***********************************************************************/
void ach::AICannon::collide(ach::PhysLine*)
{
}
