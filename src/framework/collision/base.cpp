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
	list_delete(lines);
}



/***********************************************************************
     * Collision
     * collideLines

***********************************************************************/
bool ach::Collision::collideLines(ach::Phys *phys)
{
	list_foreach(lines)
		lines[i]->check(phys);

	std::sort(lines.begin(), lines.end(), sort);


	list_foreach(lines)
	{
		lines[i]->check(phys);

		if (collideLine(phys, lines[i]))
			return true;
	}

	return false;
}



/***********************************************************************
     * Collision
     * collideLine

***********************************************************************/
bool ach::Collision::collideLine(ach::Phys *phys, ach::PhysLine *line)
{
	if (line->d == 0.0f)
		return false;

	if (line->o == 0.0f)
		return false;


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

	return true;
}
