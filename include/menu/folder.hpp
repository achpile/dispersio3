#ifndef __MENU_FOLDER
#define __MENU_FOLDER


namespace ach
{
	struct MenuItemFolder : MenuItem
	{
		std::vector<ach::MenuItem*> items;

		ach::MenuItem *leave;


		 MenuItemFolder(ach::Menu *_menu, const char *_name);
		~MenuItemFolder();

		void action();

		void add(ach::MenuItem *item);
		void finalize();

		void pick();
		void click();
	};
}

#endif
