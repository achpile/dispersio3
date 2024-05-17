#ifndef __DATA_MODEL
#define __DATA_MODEL


namespace ach
{
	struct DataModel : DataContent
	{
		ach::DataSheet *sheet;

		json_t *animation;


		 DataModel(json_t *obj);
		~DataModel();
	};
}

#endif
