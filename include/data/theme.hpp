#ifndef __DATA_THEME
#define __DATA_THEME


namespace ach
{
	struct DataTheme : DataContent
	{
		struct
		{
			ach::DataFont   *font;
			sf::Color        color;

			int              size;
		} credits;

		struct
		{
			ach::DataFont   *font;
			sf::String       selector;
			sf::Color        color;

			sf::Color        border;
			sf::Color        bg;

			sf::SoundBuffer *back;
			sf::SoundBuffer *blip;
			sf::SoundBuffer *pick;

			int              size;
		} menu;


		 DataTheme(json_t *obj);
		~DataTheme();
	};
}

#endif
