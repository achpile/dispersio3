#ifndef __DATA_MODEL
#define __DATA_MODEL


namespace ach
{
	enum ModelType
	{
		mtNone = 0,
		mtSimple,
		mtWalking
	};


	struct DataModel : DataContent
	{
		ach::ModelType  type;
		ach::DataSheet *sheet;

		json_t *animation;


		 DataModel(json_t *obj);
		~DataModel();
	};
}

#endif
