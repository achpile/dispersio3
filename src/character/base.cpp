#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(sf::Vector2f size)
{
	dead   = false;
	weapon = new ach::Weapon();

	phys.init(size);
}



/***********************************************************************
     * Character
     * destructor

***********************************************************************/
ach::Character::~Character()
{
	delete weapon;

	listDelete(models);
}



/***********************************************************************
     * Character
     * update

***********************************************************************/
void ach::Character::update()
{
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
}



/***********************************************************************
     * Character
     * shot

***********************************************************************/
void ach::Character::shot()
{
}
