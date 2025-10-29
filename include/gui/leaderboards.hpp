#ifndef __GUI_LEADERBOARDS
#define __GUI_LEADERBOARDS


namespace ach
{
	struct Leaderboards
	{
		bool active;


		 Leaderboards();
		~Leaderboards();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void init(bool highscores);
	};
}

#endif
