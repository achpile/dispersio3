#ifndef __BOSS_NONE
#define __BOSS_NONE


namespace ach
{
	struct BossNone : Boss
	{
		 BossNone(ach::ProcessWorld *_world, json_t *obj);
		~BossNone();

		void init();
	};
}

#endif
