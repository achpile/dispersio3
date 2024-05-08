#include "meta/headers.hpp"


/***********************************************************************
     * Collision
     * constructor

***********************************************************************/
ach::Collision::Collision()
{
}



/***********************************************************************
     * Collision
     * destructor

***********************************************************************/
ach::Collision::~Collision()
{
	listDelete(lines);
}



/***********************************************************************
     * Collision
     * collide

***********************************************************************/
void ach::Collision::collide(ach::Phys *phys)
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
		chunk    = (velocity == 0.0f) ? left : 4.0f / velocity;

		if (chunk > left)
			chunk = left;

		phys->pos += phys->vel * chunk;
		phys->calc();

		collideLines(phys);

		left -= chunk;
	}

	phys->calc();
}



/***********************************************************************
     * Collision
     * collideLines

***********************************************************************/
void ach::Collision::collideLines(ach::Phys *phys)
{
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		collideLine(phys, lines[i]);
	}
}



/***********************************************************************
     * Collision
     * collideLine

***********************************************************************/
void ach::Collision::collideLine(ach::Phys *, ach::PhysLine *)
{
}
