#ifndef __FRAMEWORK_MENU_LIST
#define __FRAMEWORK_MENU_LIST


namespace ach
{
	struct MenuItemList : MenuItem
	{
		 MenuItemList(ach::Menu *_menu, const char *_name);
		~MenuItemList();

		void action(int d);

		void render(int i);
		void finalize();

		void left();
		void right();
		void click();
		void rclick();
	};
}

#endif
