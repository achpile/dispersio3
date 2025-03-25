#include "meta/headers.hpp"


/***********************************************************************
     * ControlKey
     * constructor

***********************************************************************/
ach::ControlKey::ControlKey()
{
	clear(true);
	clear(false);

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
	bool current = get(true) || get(false);

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
void ach::ControlKey::clear(bool keyboard)
{
	if (keyboard) key = sf::Keyboard::Unknown;
	else          joy = ach::JoystickCode::jcUnknown;
}



/***********************************************************************
     * ControlKey
     * get

***********************************************************************/
bool ach::ControlKey::get(bool keyboard)
{
	if (keyboard) return sf::Keyboard::isKeyPressed(key);
	else          return joystick->check(joy);
}
