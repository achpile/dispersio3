#ifndef __BOSS_BOSS
#define __BOSS_BOSS


namespace ach
{
	struct Boss
	{
		ach::ProcessWorld  *world;
		ach::Character     *target;

		sf::FloatRect       rect;

		bool active;
		bool defeated;


		         Boss(ach::ProcessWorld *_world, json_t *obj);
		virtual ~Boss();

		bool update();
		void process();

		void reset();
		void check(sf::FloatRect _rect);

		virtual void init()                 {};
		virtual void handle()               {};
		virtual void respawn()              {};
		virtual void render()               {};
		virtual bool collide(sf::FloatRect) {return false;};

		static ach::Boss *create(ach::ProcessWorld *_world, json_t *obj);
	};
}

#endif
