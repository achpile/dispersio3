#ifndef __DATA_THEME
#define __DATA_THEME


namespace ach
{
	struct DataTheme : DataContent
	{
		ach::TextStyle arcade;
		ach::TextStyle credits;
		ach::TextStyle cutscene;
		ach::BoxStyle  box;

		struct
		{
			ach::TextStyle   text;
			sf::String       selector;

			ach::DataSound  *back;
			ach::DataSound  *blip;
			ach::DataSound  *pick;
		} menu;


		 DataTheme(json_t *obj);
		~DataTheme();
	};
}

#endif
