#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, ach::DataCharacter *_base)
{
	world   = _world;
	base    = _base;
	body    = ach::Body::create(this, base->body);
	weapon  = new ach::Weapon(world, base->weapon);
	dead    = false;
	speed   = base->speed;
	jumping = base->jumping;

	phys.init(base->hitbox);
}



/***********************************************************************
     * Character
     * destructor

***********************************************************************/
ach::Character::~Character()
{
	delete body;
	delete weapon;

	listDelete(models);
}



/***********************************************************************
     * Character
     * update

***********************************************************************/
void ach::Character::update()
{
	weapon->aim(phys.pos, aim);
	weapon->update();

	body->animate();
	body->update();
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
     * move

***********************************************************************/
void ach::Character::move(int d)
{
	dir.x = d; // TODO: to AI

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
