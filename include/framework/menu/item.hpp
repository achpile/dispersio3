#ifndef __FRAMEWORK_MENU_ITEM
#define __FRAMEWORK_MENU_ITEM


namespace ach
{
	struct MenuItem
	{
		std::vector<ach::MenuItem*> items;
		std::string                 caption;


		 MenuItem(std::string _caption = "");
		~MenuItem();
	};
}

#endif
