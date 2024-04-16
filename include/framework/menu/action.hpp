#ifndef __FRAMEWORK_MENU_ACTION
#define __FRAMEWORK_MENU_ACTION


namespace ach
{
	struct MenuItemAction : MenuItem
	{
		 MenuItemAction(ach::Menu *_menu, const char *_name);
		~MenuItemAction();

		void action();

		void pick();
		void click();
	};
}

#endif
