#ifndef __BOSS_MAIN
#define __BOSS_MAIN


namespace ach
{
	enum BossMainState
	{
		bmsWait,
		bmsPattern,
		bmsDamage,
		bmsDefeated
	};


	struct BossMain : Boss
	{
		ach::Model         *head;
		ach::Model         *fistL;
		ach::Model         *fistR;

		ach::BossMainState  state;
		ach::Timer          timer;
		sf::Vector2f        pos;

		int pattern;


		 BossMain(ach::ProcessWorld *_world, json_t *obj);
		~BossMain();

		void init();
		void render();
		void respawn();
		void handle();

		void prepare();
		void attack();
	};
}

#endif
