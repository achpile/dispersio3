#ifndef __DATA_MAP
#define __DATA_MAP


namespace ach
{
	struct DataMap : DataContent
	{
		 DataMap(json_t *obj);
		~DataMap();
	};
}

#endif
