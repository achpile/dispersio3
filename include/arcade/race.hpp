#ifndef __ARCADE_RACE
#define __ARCADE_RACE


namespace ach
{
	struct ArcadeRace : Arcade
	{
		 ArcadeRace(bool select);
		~ArcadeRace();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
