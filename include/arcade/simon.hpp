#ifndef __ARCADE_SIMON
#define __ARCADE_SIMON


namespace ach
{
	enum ArcadeSimonStage
	{
		Demo,
		Pause,
		Input,
		Correct,
		Create
	};


	struct ArcadeSimon : Arcade
	{
		ach::ArcadeSimonStage  stage;
		ach::Timer             ticker;
		ach::Direction         seq[ARCADE_SIMON_SIZE];

		sf::ConvexShape       *shapeUp;
		sf::ConvexShape       *shapeDown;
		sf::ConvexShape       *shapeLeft;
		sf::ConvexShape       *shapeRight;

		sf::SoundBuffer       *sndUp;
		sf::SoundBuffer       *sndDown;
		sf::SoundBuffer       *sndLeft;
		sf::SoundBuffer       *sndRight;
		sf::SoundBuffer       *sndCorr;

		bool buttons[ach::Direction::dCount];
		int  len;
		int  pos;


		 ArcadeSimon(bool select);
		~ArcadeSimon();

		void prepare();
		void process();
		void draw();
		void handle();

		void tick();
		void clear(bool value);
		void press(ach::Direction dir);
		void shape(sf::ConvexShape *shape, sf::Color c, int value);
	};
}

#endif
