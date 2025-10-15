#ifndef __DATA_BOSS
#define __DATA_BOSS


namespace ach
{
	enum BossType
	{
		btNone,
		btMain
	};


	struct DataBoss : DataContent
	{
		ach::BossType type;

		json_t *gfx;
		json_t *model;
		json_t *weapon;


		 DataBoss(json_t *obj);
		~DataBoss();
	};
}

#endif
