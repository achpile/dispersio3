#include "meta/headers.hpp"


/***********************************************************************
     * ControlKey
     * constructor

***********************************************************************/
ach::ControlKey::ControlKey()
{
	reset();
}



/***********************************************************************
     * ControlKey
     * destructor

***********************************************************************/
ach::ControlKey::~ControlKey()
{
}



/***********************************************************************
     * ControlKey
     * update

***********************************************************************/
void ach::ControlKey::update()
{
	bool current = sf::Keyboard::isKeyPressed(code);

	pressed  =  current && current != state;
	released = !current && current != state;
	state    =  current;
}



/***********************************************************************
     * ControlKey
     * reset

***********************************************************************/
void ach::ControlKey::reset()
{
	state    = false;
	pressed  = false;
	released = false;
}
