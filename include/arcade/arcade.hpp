#ifndef __ARCADE_ARCADE
#define __ARCADE_ARCADE


namespace ach
{
	enum ArcadeState
	{
		asTitle,
		asPlay,
		asGameOver
	};


	enum ArcadeGame
	{
		agNone = 0,
		agBrickOut,
		agHexagon,
		agRace,
		agSnake,
		agSimon,
		agTetris,
		agCount
	};


	struct Arcade
	{
		ach::ArcadeGame      game;
		ach::ArcadeState     state;
		ach::RectangleShape *border;
		ach::Pulse           pulse;

		sf::SoundBuffer     *pick;
		sf::SoundBuffer     *over;

		sf::RenderTexture   *tex;
		sf::Sprite          *spr;
		sf::Text            *text;
		sf::String           caption;
		sf::Vector2f         offset;

		int  score;
		int  high;
		bool active;


		         Arcade(ach::ArcadeGame _game, bool select);
		virtual ~Arcade();

		void update();
		void render();

		void renderBorder();
		void renderPress();
		void renderTitle(sf::String name);
		void renderScore(sf::String name, int value);

		void controls();

		void init();
		void quit();
		void reset();
		void stop();
		void gameover();
		void highscore();

		virtual void prepare() {};
		virtual void process() {};
		virtual void draw()    {};
		virtual void handle()  {};

		static ach::Arcade* create(ach::ArcadeGame game, bool select);
	};
}

#endif
