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
			sf::Color        border;
			sf::Color        bg;

			bool             round;
		} box;

		struct
		{
			ach::DataFont   *font;

			ach::DataSound  *back;
			ach::DataSound  *blip;
			ach::DataSound  *pick;

			sf::String       selector;
			sf::Color        color;

			int              size;
		} menu;


		 DataTheme(json_t *obj);
		~DataTheme();
	};
}

#endif
