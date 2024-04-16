#ifndef __FRAMEWORK_MENU_CHECKBOX
#define __FRAMEWORK_MENU_CHECKBOX


namespace ach
{
	struct MenuItemCheckbox : MenuItem
	{
		sf::RectangleShape *box;
		sf::RectangleShape *fill;

		bool state;


		 MenuItemCheckbox(ach::Menu *_menu, const char *_name);
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
