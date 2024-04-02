#include "meta/headers.hpp"


/***********************************************************************
     * ControlKey
     * constructor

***********************************************************************/
ach::ControlKey::ControlKey()
{
	state    = false;
	pressed  = false;
	released = false;
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
     * getKey

***********************************************************************/
std::string ach::ControlKey::getKey()
{
	switch (code)
	{
		case sf::Keyboard::A        : return "A";
		case sf::Keyboard::B        : return "B";
		case sf::Keyboard::C        : return "C";
		case sf::Keyboard::D        : return "D";
		case sf::Keyboard::E        : return "E";
		case sf::Keyboard::F        : return "F";
		case sf::Keyboard::G        : return "G";
		case sf::Keyboard::H        : return "H";
		case sf::Keyboard::I        : return "I";
		case sf::Keyboard::J        : return "J";
		case sf::Keyboard::K        : return "K";
		case sf::Keyboard::L        : return "L";
		case sf::Keyboard::M        : return "M";
		case sf::Keyboard::N        : return "N";
		case sf::Keyboard::O        : return "O";
		case sf::Keyboard::P        : return "P";
		case sf::Keyboard::Q        : return "Q";
		case sf::Keyboard::R        : return "R";
		case sf::Keyboard::S        : return "S";
		case sf::Keyboard::T        : return "T";
		case sf::Keyboard::U        : return "U";
		case sf::Keyboard::V        : return "V";
		case sf::Keyboard::W        : return "W";
		case sf::Keyboard::X        : return "X";
		case sf::Keyboard::Y        : return "Y";
		case sf::Keyboard::Z        : return "Z";
		case sf::Keyboard::Num0     : return "0";
		case sf::Keyboard::Num1     : return "1";
		case sf::Keyboard::Num2     : return "2";
		case sf::Keyboard::Num3     : return "3";
		case sf::Keyboard::Num4     : return "4";
		case sf::Keyboard::Num5     : return "5";
		case sf::Keyboard::Num6     : return "6";
		case sf::Keyboard::Num7     : return "7";
		case sf::Keyboard::Num8     : return "8";
		case sf::Keyboard::Num9     : return "9";
		case sf::Keyboard::Escape   : return "ESC";
		case sf::Keyboard::LControl : return "L-CTRL";
		case sf::Keyboard::LShift   : return "L-SHIFT";
		case sf::Keyboard::LAlt     : return "L-ALT";
		case sf::Keyboard::LSystem  : return "L-WIN";
		case sf::Keyboard::RControl : return "R-CTRL";
		case sf::Keyboard::RShift   : return "R-SHIFT";
		case sf::Keyboard::RAlt     : return "R-ALT";
		case sf::Keyboard::RSystem  : return "R-WIN";
		case sf::Keyboard::Menu     : return "MENU";
		case sf::Keyboard::LBracket : return "[";
		case sf::Keyboard::RBracket : return "]";
		case sf::Keyboard::SemiColon: return ";";
		case sf::Keyboard::Comma    : return ",";
		case sf::Keyboard::Period   : return ".";
		case sf::Keyboard::Quote    : return "'";
		case sf::Keyboard::Slash    : return "/";
		case sf::Keyboard::BackSlash: return "\\";
		case sf::Keyboard::Tilde    : return "~";
		case sf::Keyboard::Equal    : return "=";
		case sf::Keyboard::Dash     : return "-";
		case sf::Keyboard::Space    : return "SPACE";
		case sf::Keyboard::Return   : return "ENTER";
		case sf::Keyboard::BackSpace: return "BACKSPACE";
		case sf::Keyboard::Tab      : return "TAB";
		case sf::Keyboard::PageUp   : return "PAGE-UP";
		case sf::Keyboard::PageDown : return "PAGE-DOWN";
		case sf::Keyboard::End      : return "END";
		case sf::Keyboard::Home     : return "HOME";
		case sf::Keyboard::Insert   : return "INSERT";
		case sf::Keyboard::Delete   : return "DELETE";
		case sf::Keyboard::Add      : return "NUM +";
		case sf::Keyboard::Subtract : return "NUM -";
		case sf::Keyboard::Multiply : return "NUM *";
		case sf::Keyboard::Divide   : return "NUM /";
		case sf::Keyboard::Left     : return "LEFT";
		case sf::Keyboard::Right    : return "RIGHT";
		case sf::Keyboard::Up       : return "UP";
		case sf::Keyboard::Down     : return "DOWN";
		case sf::Keyboard::Numpad0  : return "NUM 0";
		case sf::Keyboard::Numpad1  : return "NUM 1";
		case sf::Keyboard::Numpad2  : return "NUM 2";
		case sf::Keyboard::Numpad3  : return "NUM 3";
		case sf::Keyboard::Numpad4  : return "NUM 4";
		case sf::Keyboard::Numpad5  : return "NUM 5";
		case sf::Keyboard::Numpad6  : return "NUM 6";
		case sf::Keyboard::Numpad7  : return "NUM 7";
		case sf::Keyboard::Numpad8  : return "NUM 8";
		case sf::Keyboard::Numpad9  : return "NUM 9";
		case sf::Keyboard::F1       : return "F1";
		case sf::Keyboard::F2       : return "F2";
		case sf::Keyboard::F3       : return "F3";
		case sf::Keyboard::F4       : return "F4";
		case sf::Keyboard::F5       : return "F5";
		case sf::Keyboard::F6       : return "F6";
		case sf::Keyboard::F7       : return "F7";
		case sf::Keyboard::F8       : return "F8";
		case sf::Keyboard::F9       : return "F9";
		case sf::Keyboard::F10      : return "F10";
		case sf::Keyboard::F11      : return "F11";
		case sf::Keyboard::F12      : return "F12";
		case sf::Keyboard::F13      : return "F13";
		case sf::Keyboard::F14      : return "F14";
		case sf::Keyboard::F15      : return "F15";
		case sf::Keyboard::Pause    : return "PAUSE";
		default                     : return "";
	}
}



/***********************************************************************
     * ControlKey
     * isKeyLegit

***********************************************************************/
bool isKeyLegit(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::A        :
		case sf::Keyboard::B        :
		case sf::Keyboard::C        :
		case sf::Keyboard::D        :
		case sf::Keyboard::E        :
		case sf::Keyboard::F        :
		case sf::Keyboard::G        :
		case sf::Keyboard::H        :
		case sf::Keyboard::I        :
		case sf::Keyboard::J        :
		case sf::Keyboard::K        :
		case sf::Keyboard::L        :
		case sf::Keyboard::M        :
		case sf::Keyboard::N        :
		case sf::Keyboard::O        :
		case sf::Keyboard::P        :
		case sf::Keyboard::Q        :
		case sf::Keyboard::R        :
		case sf::Keyboard::S        :
		case sf::Keyboard::T        :
		case sf::Keyboard::U        :
		case sf::Keyboard::V        :
		case sf::Keyboard::W        :
		case sf::Keyboard::X        :
		case sf::Keyboard::Y        :
		case sf::Keyboard::Z        :
		case sf::Keyboard::Num0     :
		case sf::Keyboard::Num1     :
		case sf::Keyboard::Num2     :
		case sf::Keyboard::Num3     :
		case sf::Keyboard::Num4     :
		case sf::Keyboard::Num5     :
		case sf::Keyboard::Num6     :
		case sf::Keyboard::Num7     :
		case sf::Keyboard::Num8     :
		case sf::Keyboard::Num9     :
		case sf::Keyboard::Escape   :
		case sf::Keyboard::LControl :
		case sf::Keyboard::LShift   :
		case sf::Keyboard::LAlt     :
		case sf::Keyboard::LSystem  :
		case sf::Keyboard::RControl :
		case sf::Keyboard::RShift   :
		case sf::Keyboard::RAlt     :
		case sf::Keyboard::RSystem  :
		case sf::Keyboard::Menu     :
		case sf::Keyboard::LBracket :
		case sf::Keyboard::RBracket :
		case sf::Keyboard::SemiColon:
		case sf::Keyboard::Comma    :
		case sf::Keyboard::Period   :
		case sf::Keyboard::Quote    :
		case sf::Keyboard::Slash    :
		case sf::Keyboard::BackSlash:
		case sf::Keyboard::Tilde    :
		case sf::Keyboard::Equal    :
		case sf::Keyboard::Dash     :
		case sf::Keyboard::Space    :
		case sf::Keyboard::Return   :
		case sf::Keyboard::BackSpace:
		case sf::Keyboard::Tab      :
		case sf::Keyboard::PageUp   :
		case sf::Keyboard::PageDown :
		case sf::Keyboard::End      :
		case sf::Keyboard::Home     :
		case sf::Keyboard::Insert   :
		case sf::Keyboard::Delete   :
		case sf::Keyboard::Add      :
		case sf::Keyboard::Subtract :
		case sf::Keyboard::Multiply :
		case sf::Keyboard::Divide   :
		case sf::Keyboard::Left     :
		case sf::Keyboard::Right    :
		case sf::Keyboard::Up       :
		case sf::Keyboard::Down     :
		case sf::Keyboard::Numpad0  :
		case sf::Keyboard::Numpad1  :
		case sf::Keyboard::Numpad2  :
		case sf::Keyboard::Numpad3  :
		case sf::Keyboard::Numpad4  :
		case sf::Keyboard::Numpad5  :
		case sf::Keyboard::Numpad6  :
		case sf::Keyboard::Numpad7  :
		case sf::Keyboard::Numpad8  :
		case sf::Keyboard::Numpad9  :
		case sf::Keyboard::F1       :
		case sf::Keyboard::F2       :
		case sf::Keyboard::F3       :
		case sf::Keyboard::F4       :
		case sf::Keyboard::F5       :
		case sf::Keyboard::F6       :
		case sf::Keyboard::F7       :
		case sf::Keyboard::F8       :
		case sf::Keyboard::F9       :
		case sf::Keyboard::F10      :
		case sf::Keyboard::F11      :
		case sf::Keyboard::F12      :
		case sf::Keyboard::F13      :
		case sf::Keyboard::F14      :
		case sf::Keyboard::F15      :
		case sf::Keyboard::Pause    :
			return true;

		default                     :
			return false;
	}
}
