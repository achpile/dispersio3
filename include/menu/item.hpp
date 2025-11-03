#ifndef __MENU_ITEM
#define __MENU_ITEM


namespace ach
{
	struct MenuItem
	{
		ach::Menu           *menu;
		ach::MenuItemFolder *parent;
		sf::String           caption;

		char name[STR_LEN_MENU];


		         MenuItem(ach::Menu *_menu, const char *_name);
		virtual ~MenuItem();

		virtual void translate();
		virtual void style()  {};

		virtual void add(ach::MenuItem *) {};
		virtual void render(int)          {};
		virtual void finalize()           {};

		virtual void left()   {};
		virtual void right()  {};
		virtual void pick()   {};
		virtual void click()  {};
		virtual void rclick() {};
	};
}

#endif
