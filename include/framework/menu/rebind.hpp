#ifndef __FRAMEWORK_MENU_REBIND
#define __FRAMEWORK_MENU_REBIND


namespace ach
{
	struct MenuItemRebind : MenuItem, MenuItemBinder
	{
		 MenuItemRebind(ach::Menu *_menu, const char *_name, bool _keyboard);
		~MenuItemRebind();

		void action();

		void pick();
		void click();

		void bind(sf::Keyboard::Key code);
		void bind(ach::JoystickCode code);
	};
}

#endif
