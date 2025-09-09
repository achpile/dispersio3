#ifndef __ARCADE_TETRIS
#define __ARCADE_TETRIS


namespace ach
{
	struct ArcadeTetris : Arcade
	{
		ach::Timer          ticker;

		sf::RectangleShape *square;
		sf::SoundBuffer    *lnd;
		sf::SoundBuffer    *line;

		sf::Vector2i        figure[4];
		sf::Vector2i        upcome[4];
		sf::Vector2i        backup[4];

		bool field[ARCADE_TETRIS_X][ARCADE_TETRIS_Y];


		 ArcadeTetris(bool select);
		~ArcadeTetris();

		void prepare();
		void process();
		void draw();
		void handle();

		void gen();
		void next();
		void tick();

		void land();
		void lines();

		void copy();
		void undo();

		bool check();
		void rotate();
		void move(int dx, int dy);

		void renderSquare(int x, int y, sf::Color color);
	};
}

#endif
