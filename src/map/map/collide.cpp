#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * collide

***********************************************************************/
void ach::Map::collide()
{
	list_foreach(characters)
		if (characters[i]->alive)
			collidePhysSteps(&characters[i]->phys);

	list_foreach(projectiles)
		collideProjectile(projectiles[i]);

	list_foreach(characters)
		collideCharacter(characters[i]);
}



/***********************************************************************
     * Map
     * collidePhysSteps

***********************************************************************/
void ach::Map::collidePhysSteps(ach::Phys *phys)
{
	phys->grounded = false;

	float left = tm->get(ach::TimeSource::tsFrame);
	float velocity;
	float chunk;

	phys->vel  += phys->acc * tm->get(ach::TimeSource::tsFrame);
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

		while (collidePhys(phys));

		left -= chunk;
	}

	phys->calc();
}



/***********************************************************************
     * Map
     * collidePhys

***********************************************************************/
bool ach::Map::collidePhys(ach::Phys *phys)
{
	std::vector<ach::PhysLine*> list;

	collision->fill(&list, &phys->rect);
	collision->sort(&list, phys);

	if (!list.size()) return false;

	list_foreach(list)
		if (list[i]->collide(phys))
			return true;

	return false;
}



/***********************************************************************
     * Map
     * collideLine

***********************************************************************/
bool ach::Map::collideLine(ach::Line *line, sf::Vector2f *n)
{
	std::vector<ach::PhysLine*> list;

	collision->fill(&list, &line->r);
	collision->sort(&list,  line);

	list_foreach(list)
		if (list[i]->collide(line))
		{
			if (n)
				*n = list[i]->line.n;

			return true;
		}

	return false;
}



/***********************************************************************
     * Map
     * collideProjectile

***********************************************************************/
void ach::Map::collideProjectile(ach::Projectile *projectile)
{
	list_foreach(characters)
		if (characters[i]->hit(projectile))
			return;

	sf::Vector2f n;

	if (collideLine(&projectile->line, &n))
	{
		projectile->phys.pos = projectile->line.b;
		projectile->hit(vector_alike(n, -projectile->line.v));
	}
}



/***********************************************************************
     * Map
     * collideExplosion

***********************************************************************/
void ach::Map::collideExplosion(ach::Projectile *projectile)
{
	list_foreach(characters)
	{
		if (characters[i]->enemy == projectile->enemy)
			continue;

		if (collision_box_vs_circle(characters[i]->phys.rect, projectile->phys.pos, projectile->base->explosionR, NULL, NULL))
			characters[i]->die();
	}
}



/***********************************************************************
     * Map
     * collideCharacter

***********************************************************************/
void ach::Map::collideCharacter(ach::Character *character)
{
	if (character->enemy)
		return;

	if (!character->alive)
		return;

	list_foreach(characters)
	{
		if (!characters[i]->alive)
			continue;

		if (character->enemy == characters[i]->enemy)
			continue;

		if (collision_box_vs_box(character->phys.rect, characters[i]->phys.rect, NULL, NULL))
		{
			character->die();

			return;
		}
	}
}
