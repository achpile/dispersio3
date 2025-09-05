#ifndef __DATA_NPC
#define __DATA_NPC


namespace ach
{
	struct DataNPC : DataContent
	{
		ach::DataModel *model;

		json_t         *speech;


		 DataNPC(json_t *obj);
		~DataNPC();
	};
}

#endif
