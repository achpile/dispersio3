#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f _spawn)
{
	world      = _world;
	base       = _base;
	spawn      = _spawn;
	ai         = ach::AI::create(this, base->ai);
	body       = ach::Body::create(this, base->body);
	weapon     = new ach::Weapon(world, this, base->weapon);
	speed      = base->speed;
	jumping    = base->jumping;
	respawning = false;


	phys.init(base->hitbox);
	spawner.set(GAME_PLAYER_RESPAWN);

	body->setColor(base->color);
	weapon->barrel = base->barrel;

	respawn();
}



/***********************************************************************
     * Character
     * destructor

***********************************************************************/
ach::Character::~Character()
{
	delete ai;
	delete body;
	delete weapon;

	list_delete(models);
}



/***********************************************************************
     * Character
     * update

***********************************************************************/
bool ach::Character::update()
{
	if (!alive)
	{
		if (!respawning)
			return false;

		if (spawner.update())
			return true;

		respawn();
	}


	body->update();

	weapon->aim(phys.pos + body->barrel, aim);
	weapon->update();

	if (phys.grounded && !landed)
		sm->play(base->sndLand);

	landed = phys.grounded;

	if (phys.grounded)
		phys.vel.y = 1.5 * speed;

	return true;
}



/***********************************************************************
     * Character
     * render

***********************************************************************/
void ach::Character::render()
{
	if (!alive)
		return;

	body->render();
}



/***********************************************************************
     * Character
     * process

***********************************************************************/
void ach::Character::process()
{
	if (!alive)
		return;

	ai->update();
}



/***********************************************************************
     * Character
     * respawn

***********************************************************************/
void ach::Character::respawn()
{
	alive    = true;
	landed   = true;
	health   = base->health;
	phys.pos = spawn;

	spawner.reset();
	reset();
}



/***********************************************************************
     * Character
     * reset

***********************************************************************/
void ach::Character::reset()
{
	aim = sf::Vector2f(1.0f, 0.0f);
	dir = sf::Vector2i(1, 0);

	body->reset();

	phys.reset();
	phys.acc.y = PHYS_GRAVITY;
	phys.vel.y = speed;
}



/***********************************************************************
     * Character
     * hit

***********************************************************************/
bool ach::Character::hit(ach::Projectile *projectile)
{
	if (enemy == projectile->enemy)
		return false;

	if (!alive)
		return false;

	if (!projectile->alive)
		return false;

	bool res;

	sf::Vector2f c;
	sf::Vector2f n;

	res = collision_box_vs_line(phys.rect, projectile->line, &c, &n);

	if (!res)
		res = collision_box_vs_box(phys.rect, projectile->phys.rect, &c, &n);


	if (res)
	{
		if (!projectile->base->explosive)
			damage(projectile->damage, c, -projectile->line.v);

		projectile->destroy();
	}

	return res;
}



/***********************************************************************
     * Character
     * damage

***********************************************************************/
void ach::Character::damage(int damage, sf::Vector2f c, sf::Vector2f n)
{
	health -= damage;

	world->map->gfx.push_back(new ach::EffectBlood(world, c, n, base->blood));

	if (health < 0)
		die(c, n);
}



/***********************************************************************
     * Character
     * die

***********************************************************************/
void ach::Character::die(sf::Vector2f c, sf::Vector2f n)
{
	alive = false;

	sm->play(base->sndDie);
	explode(c, n);
}



/***********************************************************************
     * Character
     * explode

***********************************************************************/
void ach::Character::explode(sf::Vector2f c, sf::Vector2f n)
{
	sf::Vector2f pos;
	sf::Vector2f step;
	sf::Vector2i amount;

	amount.x = ceil(phys.rect.width  / PARTICLE_CHUNK_STEP);
	amount.y = ceil(phys.rect.height / PARTICLE_CHUNK_STEP);

	step.x = phys.rect.width  / (amount.x - 1);
	step.y = phys.rect.height / (amount.y - 1);

	for (int x = 0; x < amount.x; x++)
		for (int y = 0; y < amount.y; y++)
		{
			pos.x = step.x * x + phys.rect.left;
			pos.y = step.y * y + phys.rect.top;

			chunk(pos, -vector_bisector(c - pos, n));
		}
}



/***********************************************************************
     * Character
     * chunk

***********************************************************************/
void ach::Character::chunk(sf::Vector2f pos, sf::Vector2f vel)
{
	world->map->gfx.push_back(new ach::EffectBlood(world, pos, vel, base->blood));
	world->map->gfx.push_back(new ach::EffectChunk(world, pos, vel, base->chunk, base->chunks->sheet->getFrameRandom()));
}



/***********************************************************************
     * Character
     * move

***********************************************************************/
void ach::Character::move(int d)
{
	phys.moving = true;
	phys.vel.x  = speed * d;
}



/***********************************************************************
     * Character
     * jump

***********************************************************************/
void ach::Character::jump()
{
	if (!phys.grounded)
		return;

	if (phys.jumpdown)
		return;

	phys.vel.y = -jumping;

	sm->play(base->sndJump);
}



/***********************************************************************
     * Character
     * shot

***********************************************************************/
void ach::Character::shot()
{
	weapon->shot();
}
