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
