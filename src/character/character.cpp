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
	body       = ach::Body::create(this, base->model);
	weapon     = new ach::Weapon(world, this, base->weapon);
	speed      = base->speed;
	jumping    = base->jumping;


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
}



/***********************************************************************
     * Character
     * update

***********************************************************************/
bool ach::Character::update()
{
	body->update();

	if (!alive)
	{
		if (spawner.update())
			return true;

		respawn();
	}


	weapon->aim(phys.pos + body->barrel, aim);
	weapon->update();

	if (phys.grounded && !landed)
		sm->play(base->sndLand->snd);

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
     * gateway

***********************************************************************/
void ach::Character::gateway(sf::FloatRect dest)
{
	phys.pos      = vector_placement(dest, phys.rect);
	phys.vel      = sf::Vector2f(0.0f, 0.0f);
	phys.grounded = true;
	phys.moving   = false;

	phys.calc();
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

	res = collision_box_vs_line(phys.rect, projectile->line, NULL, NULL);

	if (!res)
		res = collision_box_vs_box(phys.rect, projectile->phys.rect, NULL, NULL);


	if (res)
	{
		projectile->destroy();
		die();
	}

	return res;
}



/***********************************************************************
     * Character
     * die

***********************************************************************/
void ach::Character::die()
{
	alive = false;

	sm->play(base->sndDie->snd);
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

	sm->play(base->sndJump->snd);
}



/***********************************************************************
     * Character
     * shot

***********************************************************************/
void ach::Character::shot()
{
	weapon->shot();
}
