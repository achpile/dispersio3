#ifndef __FRAMEWORK_MENU_ITEM
#define __FRAMEWORK_MENU_ITEM


namespace ach
{
	struct MenuItem
	{
		ach::Menu   *menu;
		sf::String   caption;

		char         name[32];


		         MenuItem(ach::Menu *_menu, const char *_name);
		virtual ~MenuItem();

		void translate();

		virtual void left()   {};
		virtual void right()  {};
		virtual void pick()   {};
		virtual void click()  {};
		virtual void rclick() {};
	};
}

#endif
