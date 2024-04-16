#ifndef __FRAMEWORK_MENU_CHECKBOX
#define __FRAMEWORK_MENU_CHECKBOX


namespace ach
{
	struct MenuItemCheckbox : MenuItem
	{
		sf::RectangleShape *box;
		sf::RectangleShape *fill;

		json_t *data;

		char    var[STR_LEN_MENU];
		bool    value;


		 MenuItemCheckbox(ach::Menu *_menu, const char *_name, json_t *_data, const char *_var);
		~MenuItemCheckbox();

		void action();

		void render(int i);
		void finalize();

		void pick();
		void click();
		void rclick();
	};
}

#endif
