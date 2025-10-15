#ifndef __BOSS_BOSS
#define __BOSS_BOSS


namespace ach
{
	struct Boss
	{
		std::vector<ach::MapObjectButton*> buttons;

		ach::ProcessWorld  *world;
		ach::DataBoss      *base;
		ach::Character     *target;

		sf::FloatRect       rect;

		int  id;
		bool active;
		bool defeated;


		         Boss(ach::ProcessWorld *_world, json_t *obj);
		virtual ~Boss();

		bool update();
		void process();

		void reset();
		void search();
		void check(sf::FloatRect _rect);

		void unpress();
		void press();
		void activate();

		virtual void init()                 {};
		virtual void handle()               {};
		virtual void damage()               {};
		virtual void hit()                  {};
		virtual void respawn()              {};
		virtual void render()               {};
		virtual bool collide(sf::FloatRect) {return false;};

		static ach::Boss *create(ach::ProcessWorld *_world, json_t *obj);
	};
}

#endif
