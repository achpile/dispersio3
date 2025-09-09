#ifndef __ARCADE_RACE
#define __ARCADE_RACE


namespace ach
{
	struct ArcadeRace : Arcade
	{
		ach::Timer          ticker;
		ach::Framer         stepper;

		sf::RectangleShape *square;
		sf::Vector2i        cars[ARCADE_RACE_CARS];

		int pos;
		int step;


		 ArcadeRace(bool select);
		~ArcadeRace();

		void prepare();
		void process();
		void draw();
		void handle();

		void tick();
		void gen();
		bool collide();

		void car (int line, int x , sf::Color color);
		void line(int line        , sf::Color color);
		void tile(sf::Vector2i pos, sf::Color color);
	};
}

#endif
