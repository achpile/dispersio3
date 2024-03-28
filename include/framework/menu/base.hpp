#ifndef __FRAMEWORK_MENU_BASE
#define __FRAMEWORK_MENU_BASE


namespace ach
{
	struct Menu
	{
		ach::MenuItem* root;
		ach::MenuItem* current;


		 Menu();
		~Menu();
	};
}

#endif
