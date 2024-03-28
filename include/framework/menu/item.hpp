#ifndef __FRAMEWORK_MENU_ITEM
#define __FRAMEWORK_MENU_ITEM


namespace ach
{
	struct MenuItem
	{
		std::vector<ach::MenuItem*> items;


		 MenuItem();
		~MenuItem();
	};
}

#endif
