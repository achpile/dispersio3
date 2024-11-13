#ifndef __DATA_FONT
#define __DATA_FONT


namespace ach
{
	struct DataFont : DataContent
	{
		sf::Font *font;

		 DataFont(json_t *obj);
		~DataFont();
	};
}

#endif
