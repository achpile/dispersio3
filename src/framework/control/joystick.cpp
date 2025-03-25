#include "meta/headers.hpp"


/***********************************************************************
     * Joystick
     * constructor

***********************************************************************/
ach::Joystick::Joystick()
{
	for (int i = 0; i < CONTROL_GAMEPAD_COUNT; i++)
		state[i] = sf::Joystick::isConnected(i);
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
     * connection

***********************************************************************/
void ach::Joystick::connection(int id, bool value)
{
	state[id] = value;
}



/***********************************************************************
     * Joystick
     * axis

***********************************************************************/
bool ach::Joystick::axis(sf::Joystick::Axis axis, int sign)
{
	float pos;

	for (int i = 0; i < CONTROL_GAMEPAD_COUNT; i++)
		if (state[i])
		{
			pos = sf::Joystick::getAxisPosition(i, axis);

			if (sign == math_sign(pos) && fabs(pos) > CONTROL_GAMEPAD_GATE)
				return true;
		}

	return false;
}



/***********************************************************************
     * Joystick
     * button

***********************************************************************/
bool ach::Joystick::button(int button)
{
	for (int i = 0; i < CONTROL_GAMEPAD_COUNT; i++)
		if (state[i])
			if (sf::Joystick::isButtonPressed(i, button))
				return true;

	return false;
}



/***********************************************************************
     * Joystick
     * check

***********************************************************************/
bool ach::Joystick::check(ach::JoystickCode code)
{
	switch (code)
	{
		case ach::JoystickCode::jcAxisXminus   : return axis(sf::Joystick::X   , -1);
		case ach::JoystickCode::jcAxisXplus    : return axis(sf::Joystick::X   ,  1);
		case ach::JoystickCode::jcAxisYminus   : return axis(sf::Joystick::Y   , -1);
		case ach::JoystickCode::jcAxisYplus    : return axis(sf::Joystick::Y   ,  1);
		case ach::JoystickCode::jcAxisZminus   : return axis(sf::Joystick::Z   , -1);
		case ach::JoystickCode::jcAxisZplus    : return axis(sf::Joystick::Z   ,  1);
		case ach::JoystickCode::jcAxisRminus   : return axis(sf::Joystick::R   , -1);
		case ach::JoystickCode::jcAxisRplus    : return axis(sf::Joystick::R   ,  1);
		case ach::JoystickCode::jcAxisUminus   : return axis(sf::Joystick::U   , -1);
		case ach::JoystickCode::jcAxisUplus    : return axis(sf::Joystick::U   ,  1);
		case ach::JoystickCode::jcAxisVminus   : return axis(sf::Joystick::V   , -1);
		case ach::JoystickCode::jcAxisVplus    : return axis(sf::Joystick::V   ,  1);
		case ach::JoystickCode::jcAxisPovXminus: return axis(sf::Joystick::PovX, -1);
		case ach::JoystickCode::jcAxisPovXplus : return axis(sf::Joystick::PovX,  1);
		case ach::JoystickCode::jcAxisPovYminus: return axis(sf::Joystick::PovY, -1);
		case ach::JoystickCode::jcAxisPovYplus : return axis(sf::Joystick::PovY,  1);

		case ach::JoystickCode::jcButton1      : return button( 0);
		case ach::JoystickCode::jcButton2      : return button( 1);
		case ach::JoystickCode::jcButton3      : return button( 2);
		case ach::JoystickCode::jcButton4      : return button( 3);
		case ach::JoystickCode::jcButton5      : return button( 4);
		case ach::JoystickCode::jcButton6      : return button( 5);
		case ach::JoystickCode::jcButton7      : return button( 6);
		case ach::JoystickCode::jcButton8      : return button( 7);
		case ach::JoystickCode::jcButton9      : return button( 8);
		case ach::JoystickCode::jcButton10     : return button( 9);
		case ach::JoystickCode::jcButton11     : return button(10);
		case ach::JoystickCode::jcButton12     : return button(11);
		case ach::JoystickCode::jcButton13     : return button(12);
		case ach::JoystickCode::jcButton14     : return button(13);
		case ach::JoystickCode::jcButton15     : return button(14);
		case ach::JoystickCode::jcButton16     : return button(15);
		case ach::JoystickCode::jcButton17     : return button(16);
		case ach::JoystickCode::jcButton18     : return button(17);
		case ach::JoystickCode::jcButton19     : return button(18);
		case ach::JoystickCode::jcButton20     : return button(19);
		case ach::JoystickCode::jcButton21     : return button(20);
		case ach::JoystickCode::jcButton22     : return button(21);
		case ach::JoystickCode::jcButton23     : return button(22);
		case ach::JoystickCode::jcButton24     : return button(23);
		case ach::JoystickCode::jcButton25     : return button(24);
		case ach::JoystickCode::jcButton26     : return button(25);
		case ach::JoystickCode::jcButton27     : return button(26);
		case ach::JoystickCode::jcButton28     : return button(27);
		case ach::JoystickCode::jcButton29     : return button(28);
		case ach::JoystickCode::jcButton30     : return button(29);
		case ach::JoystickCode::jcButton31     : return button(30);
		case ach::JoystickCode::jcButton32     : return button(31);

		case ach::JoystickCode::jcUnknown      : return false;
		case ach::JoystickCode::jcCount        : return false;
	}

	return false;
}
