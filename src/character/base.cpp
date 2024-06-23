#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, ach::DataCharacter *_base)
{
	world   = _world;
	base    = _base;
	body    = new ach::Body();
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

	for (unsigned int i = 0; i < models.size(); i++)
		models[i]->update();
}



/***********************************************************************
     * Character
     * render

***********************************************************************/
void ach::Character::render()
{
	for (unsigned int i = 0; i < models.size(); i++)
		models[i]->render(phys.pos);
}



/***********************************************************************
     * Character
     * reset

***********************************************************************/
void ach::Character::reset()
{
	aim = sf::Vector2f(1.0f, 0.0f);

	phys.reset();
	phys.acc.y = PHYS_GRAVITY;
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
