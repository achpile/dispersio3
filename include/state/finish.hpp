#ifndef __STATE_FINISH
#define __STATE_FINISH


namespace ach
{
	struct StateFinish : StateBase
	{
		std::vector<ach::Statistic*> lines;

		sf::String  anykey;
		sf::String  caption;
		sf::Text   *text;

		float       life;


		 StateFinish();
		~StateFinish();

		void update();
		void render();
		void event(sf::Event);
	};
}

#endif
