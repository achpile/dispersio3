#ifndef __FRAMEWORK_MENU_THEME
#define __FRAMEWORK_MENU_THEME


namespace ach
{
	struct MenuTheme
	{
		ach::TextStyle  *text;
		ach::BoxStyle   *box;
		sf::String       selector;

		sf::SoundBuffer *back;
		sf::SoundBuffer *blip;
		sf::SoundBuffer *pick;
	};
}

#endif
