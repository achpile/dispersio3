#ifndef __DATA_SHEET
#define __DATA_SHEET


namespace ach
{
	struct DataSheet
	{
		ach::Sheet *sheet;

		char name[STR_LEN_NAME];


		 DataSheet(const char *_name, json_t *obj);
		~DataSheet();
	};
}

#endif
