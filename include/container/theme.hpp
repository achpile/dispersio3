#ifndef __CONTAINER_THEME
#define __CONTAINER_THEME


namespace ach
{
	struct Theme
	{
		ach::TextStyle *credits;
		ach::TextStyle *cutscene;
		ach::MenuTheme  menu;


		 Theme();
		~Theme();

		void refresh();
	};
}

#endif
