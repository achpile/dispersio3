#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * collide

***********************************************************************/
void ach::Map::collide()
{
	list_foreach(characters)
		if (characters[i]->alive && characters[i]->visible())
			collideCharacter(characters[i]);

	list_foreach(projectiles)
		collideProjectile(projectiles[i]);

	list_foreach(characters)
		collideEnemies(characters[i]);
}



/***********************************************************************
     * Map
     * collideCharacter

***********************************************************************/
void ach::Map::collideCharacter(ach::Character *character)
{
	character->phys.grounded = false;
	character->phys.slope    = 0.0f;

	ach::PhysLine *line;

	float left = tm->get();
	float velocity;
	float chunk;

	long filter = (character->enemy) ? filterPhysEnemy : filterPhysPlayer;

	character->phys.vel  += character->phys.acc * tm->get();
	character->phys.vel.x = interval_set(character->phys.vel.x, -PHYS_MAX_VEL, PHYS_MAX_VEL);
	character->phys.vel.y = interval_set(character->phys.vel.y, -PHYS_MAX_VEL, PHYS_MAX_VEL);


	while (left > 0.0f)
	{
		velocity = vector_len(character->phys.vel);
		chunk    = (velocity == 0.0f) ? left : 1.5f / velocity;

		if (chunk > left)
			chunk = left;

		character->phys.pos += character->phys.vel * chunk;
		character->phys.calc();

		while ((line = collidePhys(&character->phys, filter)) != NULL)
		{
			character->ai->collide(line);

			if (!character->alive)
				return;
		}

		left -= chunk;
	}

	character->phys.calc();
}



/***********************************************************************
     * Map
     * collidePhys

***********************************************************************/
ach::PhysLine* ach::Map::collidePhys(ach::Phys *phys, long filter)
{
	std::vector<ach::PhysLine*> list;

	collision->fill(&list, filter, &phys->rect);

	list_foreach(solids)
		list.push_back(solids[i]);

	collision->sort(&list, filter, phys);

	if (!list.size()) return NULL;

	list_foreach(list)
		if (list[i]->collide(phys))
			return list[i];

	return NULL;
}



/***********************************************************************
     * Map
     * collideLine

***********************************************************************/
bool ach::Map::collideLine(ach::Line *line, long filter, sf::Vector2f *n)
{
	std::vector<ach::PhysLine*> list;

	collision->fill(&list, filter, &line->r);

	list_foreach(solids)
		list.push_back(solids[i]);

	collision->sort(&list, filter, line);

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

	if (collideLine(&projectile->line, filterPhysProjectile, &n))
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
     * collideEnemies

***********************************************************************/
void ach::Map::collideEnemies(ach::Character *character)
{
	if (character->enemy)
		return;

	if (!character->alive)
		return;

	list_foreach(characters)
	{
		if (!characters[i]->alive)
			continue;

		if (!characters[i]->visible())
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
