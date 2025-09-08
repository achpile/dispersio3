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
		None = 0,
		BrickOut,
		Hexagon,
		Race,
		Snake,
		Simon,
		Tetris,
		Count
	};


	struct Arcade
	{
		ach::ArcadeState     state;
		ach::RectangleShape *border;
		ach::Timer           timer;

		sf::SoundBuffer     *pick;
		sf::SoundBuffer     *over;

		sf::RectangleShape  *square;

		sf::RenderTexture   *tex;
		sf::Sprite          *spr;
		sf::Text            *text;
		sf::String           caption;

		int  score;
		int  high;
		bool active;
		bool visible;


		         Arcade(sf::String _caption);
		virtual ~Arcade();

		void update();
		void render();

		void renderBorder();
		void renderTitle(sf::String name);
		void renderScore(sf::String name, int value);

		void controls();

		void init();
		void quit();
		void reset();
		void gameover();

		virtual void prepare() {};
		virtual void process() {};
		virtual void draw()    {};
		virtual void handle()  {};

		static ach::Arcade* create(ach::ArcadeGame game, bool select);
	};
}

#endif
