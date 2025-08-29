#ifndef __FRAMEWORK_MENU_LIST
#define __FRAMEWORK_MENU_LIST


namespace ach
{
	struct MenuItemList : MenuItem
	{
		std::vector<ach::Option*> options;
		ach::Handler              handler;

		json_t *data;
		json_t *list;

		char    var[STR_LEN_MENU];
		int     index;


		 MenuItemList(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, const char *_var, json_t *_list);
		~MenuItemList();

		void action(int d);

		void render(int i);
		void finalize();
		void translate();

		void left();
		void right();
		void click();
		void rclick();
	};
}

#endif
