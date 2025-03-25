#include "meta/headers.hpp"


/***********************************************************************
     * ControlPad
     * constructor

***********************************************************************/
ach::ControlPad::ControlPad()
{
	init();
	reset();
}



/***********************************************************************
     * ControlPad
     * destructor

***********************************************************************/
ach::ControlPad::~ControlPad()
{
}



/***********************************************************************
     * ControlPad
     * update

***********************************************************************/
void ach::ControlPad::update()
{
	for (unsigned int i = 0; i < ach::ControlAction::caCount; i++)
		keys[i].update();
}



/***********************************************************************
     * ControlPad
     * reset

***********************************************************************/
void ach::ControlPad::reset()
{
	for (unsigned int i = 0; i < ach::ControlAction::caCount; i++)
		keys[i].reset();
}



/***********************************************************************
     * ControlPad
     * clear

***********************************************************************/
void ach::ControlPad::clear(bool keyboard)
{
	for (unsigned int i = 0; i < ach::ControlAction::caCount; i++)
		keys[i].clear(keyboard);
}



/***********************************************************************
     * ControlPad
     * init

***********************************************************************/
void ach::ControlPad::init()
{
	for (int i = 0; i < ach::ControlAction::caCount; i++)
	{
		keys[i].key = settings->getKeyCode((ach::ControlAction)i);
		keys[i].joy = settings->getJoyCode((ach::ControlAction)i);
	}
}



/***********************************************************************
     * ControlPad
     * dump

***********************************************************************/
void ach::ControlPad::dump()
{
	for (int i = 0; i < ach::ControlAction::caCount; i++)
	{
		settings->setKeyCode((ach::ControlAction)i, keys[i].key);
		settings->setJoyCode((ach::ControlAction)i, keys[i].joy);
	}
}



/***********************************************************************
     * ControlPad
     * bind

***********************************************************************/
bool ach::ControlPad::bind(ach::ControlAction action, sf::Keyboard::Key code)
{
	if (!pair_has_enum(code, pairKey))
		return false;

	if (code == sf::Keyboard::Unknown)
		return false;

	for (int i = 0; i < ach::ControlAction::caCount; i++)
		if (i != action)
			if (keys[i].key == code)
				return false;

	keys[action].key = code;

	reset();

	return true;
}



/***********************************************************************
     * ControlPad
     * bind

***********************************************************************/
bool ach::ControlPad::bind(ach::ControlAction action, ach::JoystickCode code)
{
	if (!pair_has_enum(code, pairJoy))
		return false;

	if (code == ach::JoystickCode::jcUnknown)
		return false;

	for (int i = 0; i < ach::ControlAction::caCount; i++)
		if (i != action)
			if (keys[i].joy == code)
				return false;

	keys[action].joy = code;

	reset();

	return true;
}
