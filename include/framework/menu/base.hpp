#ifndef __FRAMEWORK_MENU_BASE
#define __FRAMEWORK_MENU_BASE


namespace ach
{
	struct Menu
	{
		std::vector<ach::MenuItem*> items;


		 Menu();
		~Menu();
	};
}

#endif
