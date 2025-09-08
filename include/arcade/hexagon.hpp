#ifndef __ARCADE_HEXAGON
#define __ARCADE_HEXAGON


namespace ach
{
	struct ArcadeHexagon : Arcade
	{
		 ArcadeHexagon(sf::String _caption);
		~ArcadeHexagon();

		void prepare();
		void process();
		void draw();
		void handle();
	};
}

#endif
