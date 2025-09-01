#ifndef __DATA_ITEM
#define __DATA_ITEM


namespace ach
{
	enum ItemCategory
	{
		icMisc = 0,
		icKey,
		icFreshener,
		icGame
	};


	struct DataItem : DataContent
	{
		ach::DataSheet    *sheet;
		ach::ItemCategory  category;

		char flag[STR_LEN_NAME];


		 DataItem(json_t *obj);
		~DataItem();
	};
}

#endif
