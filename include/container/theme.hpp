#ifndef __CONTAINER_THEME
#define __CONTAINER_THEME


namespace ach
{
	struct Theme
	{
		ach::MenuTheme menu;

		struct
		{
			sf::Font  *font;
			sf::Color  color;

			int        size;
		} credits;


		 Theme();
		~Theme();

		void refresh();
	};
}

#endif
