#ifndef __BOSS_MAIN
#define __BOSS_MAIN


namespace ach
{
	struct BossMain : Boss
	{
		 BossMain(ach::ProcessWorld *_world, json_t *obj);
		~BossMain();

		void init();
	};
}

#endif
