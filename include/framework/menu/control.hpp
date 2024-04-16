#ifndef __FRAMEWORK_MENU_CONTROL
#define __FRAMEWORK_MENU_CONTROL


namespace ach
{
	struct MenuItemControl : MenuItem
	{
		 MenuItemControl(ach::Menu *_menu, const char *_name);
		~MenuItemControl();
	};
}

#endif
