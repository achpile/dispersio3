#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f spawn)
{
	world   = _world;
	base    = _base;
	ai      = ach::AI::create(this, base->ai);
	body    = ach::Body::create(this, base->body);
	weapon  = new ach::Weapon(world, this, base->weapon);
	alive   = true;
	landed  = true;
	speed   = base->speed;
	jumping = base->jumping;

	weapon->barrel = base->barrel;

	body->setColor(base->color);
	phys.init(base->hitbox);

	respawn(spawn);
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
		return false;

	body->update();

	weapon->aim(phys.pos + body->barrel, aim);
	weapon->update();

	if (phys.grounded && !landed)
		sm->play(base->sndLand);

	landed = phys.grounded;

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
void ach::Character::respawn(sf::Vector2f spawn)
{
	alive    = true;
	health   = base->health;
	phys.pos = spawn;

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
		damage(projectile, c, n);
		projectile->destroy();
	}

	return res;
}



/***********************************************************************
     * Character
     * damage

***********************************************************************/
void ach::Character::damage(ach::Projectile *projectile, sf::Vector2f , sf::Vector2f )
{
	health -= projectile->damage;
}



/***********************************************************************
     * Character
     * move

***********************************************************************/
void ach::Character::move(int d)
{
	phys.moving = true;
	phys.vel.x  = speed * d;

	if (phys.grounded)
		phys.vel.y = 1.5 * speed;
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
