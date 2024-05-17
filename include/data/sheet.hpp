#ifndef __DATA_SHEET
#define __DATA_SHEET


namespace ach
{
	struct DataSheet : DataContent
	{
		ach::Sheet *sheet;


		 DataSheet(json_t *obj);
		~DataSheet();
	};
}

#endif
