#ifndef __MENU_RESET
#define __MENU_RESET


namespace ach
{
	struct MenuItemReset : MenuItem
	{
		bool keyboard;


		 MenuItemReset(ach::Menu *_menu, const char *_name, bool _keyboard);
		~MenuItemReset();

		void action();

		void pick();
		void click();
	};
}

#endif
