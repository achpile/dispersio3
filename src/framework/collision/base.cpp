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
		chunk    = (velocity == 0.0f) ? left : 1.5f / velocity;

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
		lines[i]->check(phys);
		collideLine(phys, lines[i]);
	}
}



/***********************************************************************
     * Collision
     * collideLine

***********************************************************************/
void ach::Collision::collideLine(ach::Phys *phys, ach::PhysLine *line)
{
	if (line->d == 0.0f)
		return;

	if (line->o == 0.0f)
		return;


	sf::Vector2f offset = line->offset();

	if (offset.y < 0.0f)
		phys->grounded = true;

	if (offset.y != 0.0f)
		phys->vel.y = 0.0f;

	if (offset.x != 0.0f)
	{
		phys->moving = false;
		phys->vel.x  = 0.0f;
	}

	phys->pos += offset;
	phys->calc();
}
