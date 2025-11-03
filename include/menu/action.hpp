#ifndef __MENU_ACTION
#define __MENU_ACTION


namespace ach
{
	struct MenuItemAction : MenuItem
	{
		ach::Handler  handler;

		json_t       *param;


		 MenuItemAction(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_param);
		~MenuItemAction();

		void action();

		void pick();
		void click();
	};
}

#endif
