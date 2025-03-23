#ifndef __DATA_MAP
#define __DATA_MAP


namespace ach
{
	struct DataMap : DataContent
	{
		ach::DataCharacter *player;
		sf::Vector2i        spawn;

		char filename[STR_LEN_PATH];
		char track   [STR_LEN_PATH];


		 DataMap(json_t *obj);
		~DataMap();
	};
}

#endif
