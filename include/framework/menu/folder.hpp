#ifndef __FRAMEWORK_MENU_FOLDER
#define __FRAMEWORK_MENU_FOLDER


namespace ach
{
	struct MenuItemFolder : MenuItem
	{
		std::vector<ach::MenuItem*> items;


		 MenuItemFolder(ach::Menu *_menu, const char *_name);
		~MenuItemFolder();

		void add(ach::MenuItem *item);
		void finalize();

		void action();

		void pick();
		void click();
	};
}

#endif
