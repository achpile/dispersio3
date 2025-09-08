#ifndef __ARCADE_SIMON
#define __ARCADE_SIMON


namespace ach
{
	struct ArcadeSimon : Arcade
	{
		 ArcadeSimon(sf::String _caption);
		~ArcadeSimon();

		void process();
		void draw();
		void handle();
	};
}

#endif
