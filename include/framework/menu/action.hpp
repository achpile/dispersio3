#ifndef __FRAMEWORK_MENU_ACTION
#define __FRAMEWORK_MENU_ACTION


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
