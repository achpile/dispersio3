#ifndef __MENU_BINDER
#define __MENU_BINDER


namespace ach
{
	struct MenuItemBinder
	{
		ach::ControlPad *binder;

		bool binding;
		bool keyboard;


		virtual void bind(sf::Keyboard::Key) {};
		virtual void bind(ach::JoystickCode) {};

		virtual void cancel() {};

		bool assign(ach::ControlAction act, sf::Keyboard::Key code);
		bool assign(ach::ControlAction act, ach::JoystickCode code);

		void apply();
	};
}

#endif
