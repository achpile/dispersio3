#ifndef __ARCADE_RACE
#define __ARCADE_RACE


namespace ach
{
	struct ArcadeRace : Arcade
	{
		 ArcadeRace(sf::String _caption);
		~ArcadeRace();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
