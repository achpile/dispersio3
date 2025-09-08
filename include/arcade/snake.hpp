#ifndef __ARCADE_SNAKE
#define __ARCADE_SNAKE


namespace ach
{
	struct ArcadeSnake : Arcade
	{
		std::vector<sf::Vector2i> snake;

		ach::Timer          ticker;
		ach::Direction      dir;
		ach::Direction      next;

		sf::SoundBuffer    *eat;
		sf::SoundBuffer    *clear;
		sf::Vector2i        fruit;


		 ArcadeSnake(bool select);
		~ArcadeSnake();

		void prepare();
		void process();
		void draw();
		void handle();

		void gen();
		void tick();
		bool move();
		void turn(ach::Direction _dir);
	};
}

#endif
