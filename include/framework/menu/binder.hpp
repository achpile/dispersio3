#ifndef __FRAMEWORK_MENU_BINDER
#define __FRAMEWORK_MENU_BINDER


namespace ach
{
	struct MenuItemBinder
	{
		ach::ControlPad *binder;

		bool binding;
		bool keyboard;


		virtual void bind(sf::Keyboard::Key) {};
		virtual void bind(ach::JoystickCode) {};

		bool assign(ach::ControlAction act, sf::Keyboard::Key code);
		bool assign(ach::ControlAction act, ach::JoystickCode code);

		void apply();
	};
}

#endif
