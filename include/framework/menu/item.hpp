#ifndef __FRAMEWORK_MENU_ITEM
#define __FRAMEWORK_MENU_ITEM


namespace ach
{
	struct MenuItem
	{
		ach::Menu     *menu;
		ach::MenuItem *parent;
		sf::String     caption;

		char           name[STR_LEN_MENU];


		         MenuItem(ach::Menu *_menu, const char *_name);
		virtual ~MenuItem();

		void translate();

		virtual void add(ach::MenuItem *) {};
		virtual void finalize()           {};

		virtual void left()   {};
		virtual void right()  {};
		virtual void pick()   {};
		virtual void click()  {};
		virtual void rclick() {};
	};
}

#endif
