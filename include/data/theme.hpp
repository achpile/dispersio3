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

			ach::DataSound  *back;
			ach::DataSound  *blip;
			ach::DataSound  *pick;

			sf::String       selector;

			sf::Color        color;
			sf::Color        border;
			sf::Color        bg;

			int              size;
			bool             round;
		} menu;


		 DataTheme(json_t *obj);
		~DataTheme();
	};
}

#endif
