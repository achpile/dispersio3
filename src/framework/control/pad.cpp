#include "meta/headers.hpp"


/***********************************************************************
     * ControlPad
     * constructor

***********************************************************************/
ach::ControlPad::ControlPad()
{
	keys[ach::ControlAction::caUp   ].code = sf::Keyboard::Up;
	keys[ach::ControlAction::caDown ].code = sf::Keyboard::Down;
	keys[ach::ControlAction::caLeft ].code = sf::Keyboard::Left;
	keys[ach::ControlAction::caRight].code = sf::Keyboard::Right;
	keys[ach::ControlAction::caJump ].code = sf::Keyboard::Space;
	keys[ach::ControlAction::caMenu ].code = sf::Keyboard::Escape;
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
     * bind

***********************************************************************/
bool ach::ControlPad::bind(ach::ControlAction action, sf::Keyboard::Key code)
{
	if (!ach::ControlKey::isKeyLegit(code))
		return false;

	for (int i = 0; i < ach::ControlAction::caCount; i++)
		if (i != action)
			if (keys[i].code == code)
				return false;

	keys[action].code = code;
	reset();

	return true;
}
