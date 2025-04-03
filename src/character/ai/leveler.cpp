#include "meta/headers.hpp"


/***********************************************************************
     * AILeveler
     * constructor

***********************************************************************/
ach::AILeveler::AILeveler(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	cooldown = json_class_get_real(obj, "Shooting", "Cooldown");
	offset   = json_class_get_real(obj, "Shooting", "Offset"  );
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
	search();

	if (target)
		owner->dir.x = math_sign(target->phys.pos.x - owner->phys.pos.x);

	owner->aim      = sf::Vector2f(owner->dir.x, 0.0f);
	owner->phys.vel = sf::Vector2f(0.0f, math_sign(math_sign(target->phys.pos.y - owner->phys.pos.y))) * owner->speed;
}



/***********************************************************************
     * AILeveler
     * reset

***********************************************************************/
void ach::AILeveler::reset()
{
	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}
