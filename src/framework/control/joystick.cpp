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
	switch (code)
	{
		case ach::JoystickCode::jcAxisXminus   : return axis(sf::Joystick::X   , false);
		case ach::JoystickCode::jcAxisXplus    : return axis(sf::Joystick::X   , true );
		case ach::JoystickCode::jcAxisYminus   : return axis(sf::Joystick::Y   , false);
		case ach::JoystickCode::jcAxisYplus    : return axis(sf::Joystick::Y   , true );
		case ach::JoystickCode::jcAxisZminus   : return axis(sf::Joystick::Z   , false);
		case ach::JoystickCode::jcAxisZplus    : return axis(sf::Joystick::Z   , true );
		case ach::JoystickCode::jcAxisRminus   : return axis(sf::Joystick::R   , false);
		case ach::JoystickCode::jcAxisRplus    : return axis(sf::Joystick::R   , true );
		case ach::JoystickCode::jcAxisUminus   : return axis(sf::Joystick::U   , false);
		case ach::JoystickCode::jcAxisUplus    : return axis(sf::Joystick::U   , true );
		case ach::JoystickCode::jcAxisVminus   : return axis(sf::Joystick::V   , false);
		case ach::JoystickCode::jcAxisVplus    : return axis(sf::Joystick::V   , true );
		case ach::JoystickCode::jcAxisPovXminus: return axis(sf::Joystick::PovX, false);
		case ach::JoystickCode::jcAxisPovXplus : return axis(sf::Joystick::PovX, true );
		case ach::JoystickCode::jcAxisPovYminus: return axis(sf::Joystick::PovY, false);
		case ach::JoystickCode::jcAxisPovYplus : return axis(sf::Joystick::PovY, true );

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



/***********************************************************************
     * Joystick
     * axis

***********************************************************************/
bool ach::Joystick::axis(sf::Joystick::Axis axis, bool plus)
{
	(void)axis;
	(void)plus;

	return false;
}



/***********************************************************************
     * Joystick
     * button

***********************************************************************/
bool ach::Joystick::button(unsigned int button)
{
	(void)button;

	return false;
}
