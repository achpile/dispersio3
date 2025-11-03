#ifndef __MENU_BACK
#define __MENU_BACK


namespace ach
{
	struct MenuItemBack : MenuItem
	{
		 MenuItemBack(ach::Menu *_menu, const char *_name);
		~MenuItemBack();

		void action();

		void pick();
		void click();
	};
}

#endif
