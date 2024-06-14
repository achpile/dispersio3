#include "meta/headers.hpp"


/***********************************************************************
     * Weapon
     * constructor

***********************************************************************/
ach::Weapon::Weapon(ach::ProcessWorld *_world, ach::DataWeapon *_base)
{
	world = _world;
	base  = _base;

	cooldown.set(base->cooldown);
	cooldown.zero();
}



/***********************************************************************
     * Weapon
     * destructor

***********************************************************************/
ach::Weapon::~Weapon()
{
}



/***********************************************************************
     * Weapon
     * update

***********************************************************************/
void ach::Weapon::update()
{
	cooldown.update();
}



/***********************************************************************
     * Weapon
     * shot

***********************************************************************/
void ach::Weapon::shot()
{
	if (cooldown.isActive())
		return;

	cooldown.reset();
	sm->play(base->shot);
}
