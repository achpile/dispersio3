#ifndef __DATA_NPC
#define __DATA_NPC


namespace ach
{
	struct DataNPC : DataContent
	{
		ach::DataModel *model;

		json_t         *speech;
		bool            wander;


		 DataNPC(json_t *obj);
		~DataNPC();
	};
}

#endif
