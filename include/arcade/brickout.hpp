#ifndef __ARCADE_BRICKOUT
#define __ARCADE_BRICKOUT


namespace ach
{
	struct ArcadeBrickOut : Arcade
	{
		sf::SoundBuffer    *wall;
		sf::SoundBuffer    *hit;
		sf::SoundBuffer    *clear;

		sf::RectangleShape *pad;
		sf::RectangleShape *tile;
		sf::RectangleShape *square;

		sf::Vector2f        pos;
		sf::Vector2f        vel;

		bool  tiles[ARCADE_BRICKOUT_X][ARCADE_BRICKOUT_Y];
		bool  glue;
		int   lives;
		float x;


		 ArcadeBrickOut(bool select);
		~ArcadeBrickOut();

		void prepare();
		void process();
		void draw();
		void handle();

		void fill();
		void move(int d);
		void action();
		void shot();
		void die();
		void finish();
		bool check();

		void collidePad();
		void collideTiles();
		void collideTile(int i, int j);

		void renderPad();
		void renderLives();
		void renderSquare();
		void renderTiles();
		void renderTile(int i, int j);
	};
}

#endif
