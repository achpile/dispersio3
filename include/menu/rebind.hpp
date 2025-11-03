#ifndef __MENU_REBIND
#define __MENU_REBIND


namespace ach
{
	struct MenuItemRebind : MenuItem, MenuItemBinder
	{
		int act = 0;


		 MenuItemRebind(ach::Menu *_menu, const char *_name, bool _keyboard);
		~MenuItemRebind();

		void action();

		void pick();
		void click();

		void bind(sf::Keyboard::Key code);
		void bind(ach::JoystickCode code);

		void next();
		void cancel();
	};
}

#endif
