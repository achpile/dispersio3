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
		ach::Model          *head;
		ach::Model          *eyes;
		ach::Model          *mouth;
		ach::Model          *fistL;
		ach::Model          *fistR;

		ach::DataProjectile *projectile;

		ach::BossMainState   state;
		ach::Timer           timer;
		sf::Vector2f         pos;

		std::vector<int>     list;

		int pattern;


		 BossMain(ach::ProcessWorld *_world, json_t *obj);
		~BossMain();

		void init();
		void render();
		void respawn();
		void handle();
		bool collide(sf::FloatRect r);

		int  count();
		void idle();
		void patterns();

		void shot(sf::Vector2f _pos, sf::Vector2f _dir, float _vel);

		void prepare();
		void evaluate();
		void attack();
	};
}

#endif
