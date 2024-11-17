#include "meta/headers.hpp"


/***********************************************************************
     * Weapon
     * constructor

***********************************************************************/
ach::Weapon::Weapon(ach::ProcessWorld *_world, ach::Character *_owner, ach::DataWeapon *_base)
{
	world = _world;
	owner = _owner;
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
     * aim

***********************************************************************/
void ach::Weapon::aim(sf::Vector2f p, sf::Vector2f v)
{
	pos   = p;
	angle = vector_angle(v);
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

	for (int i = 0; i < base->count; i++)
	{
		ach::Projectile *proj = new ach::Projectile(world, base->projectile);

		proj->range     = base->range;
		proj->enemy     = owner->enemy;
		proj->phys.vel  = vector_set_len(vector_create(angle + random_float(base->cone * MATH_RAD)), base->speed);
		proj->phys.pos  = pos + vector_set_len(proj->phys.vel, barrel);

		if (proj->phys.vel.x < 0.0f)
			proj->flip = true;

		proj->init();

		world->map->projectiles.push_back(proj);
	}
}
