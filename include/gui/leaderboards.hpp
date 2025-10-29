#ifndef __GUI_LEADERBOARDS
#define __GUI_LEADERBOARDS


namespace ach
{
	struct LeaderboardsData
	{
		ach::Leaderboard *lb;
		sf::String        caption;
	};


	struct Leaderboards
	{
		std::vector<ach::LeaderboardsData> data;

		ach::RectangleShape  *boxSelect;
		ach::RectangleShape  *boxClass;
		ach::RectangleShape  *boxList;
		ach::RectangleShape  *boxBack;

		sf::Vector2f          pos;

		bool  active;

		float padding;
		float spacing;


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
