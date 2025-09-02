#ifndef __DATA_MAP
#define __DATA_MAP


namespace ach
{
	struct DataMap : DataContent
	{
		ach::DataCharacter *player;
		ach::Sprite        *preview;
		sf::Vector2i        spawn;

		char filename[STR_LEN_PATH];
		char track   [STR_LEN_PATH];
		char next    [STR_LEN_NAME];

		bool finish;
		bool replay;
		bool restart;

		int  items;


		 DataMap(json_t *obj);
		~DataMap();

		void calc();
	};
}

#endif
