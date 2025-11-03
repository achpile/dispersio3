#ifndef __FRAMEWORK_MENU_REBIND
#define __FRAMEWORK_MENU_REBIND


namespace ach
{
	struct MenuItemRebind : MenuItem, MenuItemBinder
	{
		ach::Handler  handler;

		int           act = 0;


		 MenuItemRebind(ach::Menu *_menu, const char *_name, ach::Handler _handler, bool _keyboard);
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
