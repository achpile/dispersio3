#ifndef __FRAMEWORK_MENU_BINDER
#define __FRAMEWORK_MENU_BINDER


namespace ach
{
	struct MenuItemBinder
	{
		bool isBinding;
		bool keyboard;


		virtual void bind(sf::Keyboard::Key) {};
		virtual void bind(ach::JoystickCode) {};
	};
}

#endif
