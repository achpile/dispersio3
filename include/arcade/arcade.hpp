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
		ach::Score           score;

		sf::SoundBuffer     *pick;
		sf::SoundBuffer     *over;

		sf::RenderTexture   *tex;
		sf::Sprite          *spr;
		sf::Text            *text;
		sf::String           caption;
		sf::Vector2f         offset;

		int  rank;
		int  best;
		int  high;
		bool active;
		bool updated;


		         Arcade(ach::ArcadeGame _game, bool select);
		virtual ~Arcade();

		void update();
		void render();

		void renderBorder();
		void renderPress();
		void renderTitle(sf::String name);
		void renderValue(sf::String name, int y, int value, bool zero);

		void controls();

		void init();
		void quit();
		void reset();
		void stop();
		void gameover();
		void highscore();
		void sync();

		virtual void prepare() {};
		virtual void process() {};
		virtual void draw()    {};
		virtual void handle()  {};

		static ach::Arcade* create(ach::ArcadeGame game, bool select);
	};
}

#endif
