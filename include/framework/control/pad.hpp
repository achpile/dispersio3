#ifndef __FRAMEWORK_CONTROL_PAD
#define __FRAMEWORK_CONTROL_PAD


namespace ach
{
	enum ControlAction
	{
		caUp = 0,
		caDown,
		caLeft,
		caRight,
		caJump,
		caMenu,
		caCount
	};


	struct ControlPad
	{
		ach::ControlKey keys[ach::ControlAction::caCount];


		 ControlPad();
		~ControlPad();

		void update();
		void reset();
		void clear();

		void init();
		void dump();

		bool bind(ach::ControlAction action, sf::Keyboard::Key code);
		bool bind(ach::ControlAction action, ach::JoystickCode code);
	};
}

#endif
