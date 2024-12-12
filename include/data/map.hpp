#ifndef __DATA_MAP
#define __DATA_MAP


namespace ach
{
	struct DataMap : DataContent
	{
		ach::DataParallax *parallax;
		sf::Vector2i       spawn;

		char filename[STR_LEN_PATH];
		bool stars;


		 DataMap(json_t *obj);
		~DataMap();
	};
}

#endif
