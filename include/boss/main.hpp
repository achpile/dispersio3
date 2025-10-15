#ifndef __BOSS_MAIN
#define __BOSS_MAIN


namespace ach
{
	enum BossMainState
	{
		bmsWait,
		bmsPrepare,
		bmsPattern,
		bmsDamage,
		bmsDefeated
	};


	struct BossMain : Boss
	{
		ach::Model         *head;
		ach::Model         *eyes;
		ach::Model         *mouth;
		ach::Model         *fistL;
		ach::Model         *fistR;

		ach::DataSheet     *warning;
		ach::DataSheet     *explosion;
		ach::DataSheet     *boulder;
		ach::DataSound     *expl;
		ach::DataWeapon    *weapon;

		ach::BossMainState  state;
		ach::Timer          timer;
		sf::Vector2f        pos;

		std::vector<int>    list;

		float offsetL;
		float offsetR;

		int   counter;
		int   pattern;


		 BossMain(ach::ProcessWorld *_world, json_t *obj);
		~BossMain();

		void init();
		void render();
		void respawn();
		void handle();
		void damage();
		void hit();
		bool collide(sf::FloatRect r);

		int  count();
		void idle();
		void patterns();

		void warn(sf::Vector2f _pos);
		void aim (sf::Vector2f _pos, sf::Vector2f _dest);
		void shot(sf::Vector2f _pos, sf::Vector2f _dir);

		void prepare();
		void warnings();
		void initialize();
		void evaluate();
		void attack();
	};
}

#endif
