#include "meta/headers.hpp"


/***********************************************************************
     * AISniper
     * constructor

***********************************************************************/
ach::AISniper::AISniper(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
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
}



/***********************************************************************
     * AISniper
     * aim

***********************************************************************/
void ach::AISniper::aim()
{
}



/***********************************************************************
     * AISniper
     * reset

***********************************************************************/
void ach::AISniper::reset()
{
	owner->aim = dir_vector_f(ach::Direction::dDown);

	owner->weapon->setCooldown(cooldown);
	owner->weapon->setOffset  (offset);
}
