#ifndef __FRAMEWORK_MENU_CHECKBOX
#define __FRAMEWORK_MENU_CHECKBOX


namespace ach
{
	struct MenuItemCheckbox : MenuItem
	{
		 MenuItemCheckbox(ach::Menu *_menu, const char *_name);
		~MenuItemCheckbox();
	};
}

#endif
