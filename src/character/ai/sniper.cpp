#include "meta/headers.hpp"


/***********************************************************************
     * AISniper
     * constructor

***********************************************************************/
ach::AISniper::AISniper(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	initial  = pair_get_enum(json_class_get_string(obj, "Moving"  , "Direction"), pairDirection);
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
     * control

***********************************************************************/
void ach::AISniper::control()
{
	search();

	owner->phys.vel = dir_vector_f(dir) * owner->speed;
}



/***********************************************************************
     * AISniper
     * aim

***********************************************************************/
void ach::AISniper::aim()
{
	if (!target)
		return;

	owner->aim    = vector_norm(target->phys.pos - owner->phys.pos);
	owner->dir.x  = math_sign(owner->aim.x);

	if (!owner->dir.x)
		owner->dir.x = 1;
}



/***********************************************************************
     * AISniper
     * reset

***********************************************************************/
void ach::AISniper::reset()
{
	dir = initial;

	owner->aim = dir_vector_f(ach::Direction::dDown);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}



/***********************************************************************
     * AISniper
     * collide

***********************************************************************/
void ach::AISniper::collide(ach::PhysLine*)
{
	dir = !dir;
}
