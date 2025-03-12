#include "meta/headers.hpp"


/***********************************************************************
     * AISniper
     * constructor

***********************************************************************/
ach::AISniper::AISniper(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	dir      = pair_get_enum(json_class_get_string(obj, "Shooting", "Aim"), pairDirection);
	cooldown = json_class_get_real(obj, "Shooting", "Cooldown");
	offset   = json_class_get_real(obj, "Shooting", "Offset"  );
}



/***********************************************************************
     * AISniper
     * destructor

***********************************************************************/
ach::AISniper::~AISniper()
{
}



/***********************************************************************
     * AISniper
     * reset

***********************************************************************/
void ach::AISniper::reset()
{
	owner->aim = dir_vector_f(dir);
	owner->body->setDirection(dir);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}
