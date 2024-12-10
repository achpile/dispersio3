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
		caShot,
		caUse,
		caHold,
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

		void init();
		bool bind(ach::ControlAction action, sf::Keyboard::Key code);
	};
}

#endif
