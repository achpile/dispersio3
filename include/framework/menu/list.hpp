#ifndef __FRAMEWORK_MENU_LIST
#define __FRAMEWORK_MENU_LIST


namespace ach
{
	struct MenuItemList : MenuItem
	{
		std::vector<ach::Option> options;

		json_t *data;

		int     index;
		bool    token;


		 MenuItemList(ach::Menu *_menu, const char *_name, json_t *_data);
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
