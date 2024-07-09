#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * collide

***********************************************************************/
void ach::Map::collide()
{
	list_foreach(characters)
		collidePhys(&characters[i]->phys);

	// collide bullets <-> characters

	list_foreach(projectiles)
		collideProjectile(projectiles[i]);
}



/***********************************************************************
     * Map
     * collidePhys

***********************************************************************/
void ach::Map::collidePhys(ach::Phys *phys)
{
	phys->grounded = false;

	float left = tm->frame;
	float velocity;
	float chunk;

	phys->vel  += phys->acc * tm->frame;
	phys->vel.x = interval_set(phys->vel.x, -PHYS_MAX_VEL, PHYS_MAX_VEL);
	phys->vel.y = interval_set(phys->vel.y, -PHYS_MAX_VEL, PHYS_MAX_VEL);


	while (left > 0.0f)
	{
		velocity = vector_len(phys->vel);
		chunk    = (velocity == 0.0f) ? left : 1.5f / velocity;

		if (chunk > left)
			chunk = left;

		phys->pos += phys->vel * chunk;
		phys->calc();

		while (collision->collideLines(phys));

		left -= chunk;
	}

	phys->calc();
}



/***********************************************************************
     * Map
     * collideProjectile

***********************************************************************/
void ach::Map::collideProjectile(ach::Projectile *)
{
	
}
