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
		ach::LeaderboardClass              type;

		ach::RectangleShape  *boxSelect;
		ach::RectangleShape  *boxClass;
		ach::RectangleShape  *boxList;
		ach::RectangleShape  *boxBack;

		sf::Text             *text;
		sf::String            category;
		sf::String            back;
		sf::Vector2f          pos;

		bool  highscores;
		bool  active;
		int   index;

		float padding;
		float spacing;
		float width;


		 Leaderboards();
		~Leaderboards();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void init(bool _highscores);

		void add(const char *name, sf::String caption);
	};
}

#endif
