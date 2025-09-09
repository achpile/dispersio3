#ifndef __ARCADE_RACE
#define __ARCADE_RACE


namespace ach
{
	struct ArcadeRace : Arcade
	{
		ach::Timer          ticker;

		sf::RectangleShape *square;

		int pos;
		int step;
		int lines[3];


		 ArcadeRace(bool select);
		~ArcadeRace();

		void prepare();
		void process();
		void draw();
		void handle();

		void tick();

		void car (int line, int x , sf::Color color);
		void line(int line        , sf::Color color);
		void tile(sf::Vector2i pos, sf::Color color);
	};
}

#endif
