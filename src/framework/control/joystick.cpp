#include "meta/headers.hpp"


/***********************************************************************
     * Joystick
     * constructor

***********************************************************************/
ach::Joystick::Joystick()
{
}



/***********************************************************************
     * Joystick
     * destructor

***********************************************************************/
ach::Joystick::~Joystick()
{
}



/***********************************************************************
     * Joystick
     * update

***********************************************************************/
void ach::Joystick::update()
{
	sf::Joystick::update();
}



/***********************************************************************
     * Joystick
     * check

***********************************************************************/
bool ach::Joystick::check(ach::JoystickCode code)
{
	if (code)
		return false;

	return false;
}
