#ifndef __BOSS_MAIN
#define __BOSS_MAIN


namespace ach
{
	struct BossMain : Boss
	{
		ach::Model   *head;
		ach::Model   *fistL;
		ach::Model   *fistR;

		sf::Vector2f  pos;


		 BossMain(ach::ProcessWorld *_world, json_t *obj);
		~BossMain();

		void init();
		void render();
	};
}

#endif
