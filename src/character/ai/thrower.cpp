#include "meta/headers.hpp"


/***********************************************************************
     * AIThrower
     * constructor

***********************************************************************/
ach::AIThrower::AIThrower(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	aim      = pair_get_enum(json_class_get_string(obj, "Shooting", "Aim"      ), pairDirection);
	cooldown = json_class_get_real(obj, "Shooting", "Cooldown");
	offset   = json_class_get_real(obj, "Shooting", "Offset"  );
}



/***********************************************************************
     * AIThrower
     * destructor

***********************************************************************/
ach::AIThrower::~AIThrower()
{
}



/***********************************************************************
     * AIThrower
     * control

***********************************************************************/
void ach::AIThrower::control()
{
	owner->aim = vector_norm(dir_vector_f(aim) + sf::Vector2f(0.0f, -2.0f));
}



/***********************************************************************
     * AIThrower
     * reset

***********************************************************************/
void ach::AIThrower::reset()
{
	owner->dir.x = dir_sign(aim);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}
