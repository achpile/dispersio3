#ifndef __FRAMEWORK_MENU_THEME
#define __FRAMEWORK_MENU_THEME


namespace ach
{
	struct MenuTheme
	{
		sf::Font        *font;
		sf::String       selector;
		sf::Color        color;

		sf::Color        border;
		sf::Color        bg;

		sf::SoundBuffer *back;
		sf::SoundBuffer *blip;
		sf::SoundBuffer *pick;

		int              size;
		int              spacing;
	};
}

#endif
