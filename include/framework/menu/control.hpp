#ifndef __FRAMEWORK_MENU_CONTROL
#define __FRAMEWORK_MENU_CONTROL


namespace ach
{
	struct MenuItemControl : MenuItem
	{
		ach::ControlAction action;


		 MenuItemControl(ach::Menu *_menu, ach::ControlAction _action);
		~MenuItemControl();

		void render(int i);
		void translate();
	};
}

#endif
