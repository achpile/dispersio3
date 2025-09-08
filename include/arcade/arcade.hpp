#ifndef __ARCADE_ARCADE
#define __ARCADE_ARCADE


namespace ach
{
	enum ArcadeState
	{
		Title,
		Play,
		GameOver
	};


	enum ArcadeGame
	{
		None,
		BrickOut,
		F1,
		Hexagon,
		Snake,
		Simon,
		Tetris
	};


	struct Arcade
	{
		ach::ArcadeState     state;
		ach::RectangleShape *border;

		sf::RectangleShape  *square;

		sf::RenderTexture   *tex;
		sf::Sprite          *spr;

		int  score;
		int  high;
		bool active;


		         Arcade();
		virtual ~Arcade();

		void update();
		void render();

		void controls();

		virtual void process() {};
		virtual void draw()    {};
		virtual void handle()  {};

		static ach::Arcade* create();
	};
}

#endif
