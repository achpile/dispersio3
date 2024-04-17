#ifndef __FRAMEWORK_MENU_LIST
#define __FRAMEWORK_MENU_LIST


namespace ach
{
	struct MenuItemList : MenuItem
	{
		std::vector<ach::Option> options;
		ach::Handler             handler;

		json_t *data;
		json_t *list;

		int     index;
		bool    token;


		 MenuItemList(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, json_t *_list, bool _token);
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
