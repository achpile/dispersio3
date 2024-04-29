#ifndef __DATA_MODEL
#define __DATA_MODEL


namespace ach
{
	struct DataModel
	{
		ach::Sheet *sheet;

		json_t *animation;
		char    name[STR_LEN_NAME];


		 DataModel(const char *_name, json_t *obj);
		~DataModel();
	};
}

#endif
