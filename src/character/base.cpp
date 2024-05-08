#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(sf::Vector2f size)
{
	phys.init(size);
}



/***********************************************************************
     * Character
     * destructor

***********************************************************************/
ach::Character::~Character()
{
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
