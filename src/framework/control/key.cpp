#include "meta/headers.hpp"


/***********************************************************************
     * ControlKey
     * constructor

***********************************************************************/
ach::ControlKey::ControlKey()
{
	clear();
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
	bool current = sf::Keyboard::isKeyPressed(key) || joystick->check(joy);

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
	state    = true;
	pressed  = false;
	released = false;
}



/***********************************************************************
     * ControlKey
     * clear

***********************************************************************/
void ach::ControlKey::clear()
{
	key      = sf::Keyboard::Unknown;
	joy      = ach::JoystickCode::jcUnknown;
}
