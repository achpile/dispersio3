#ifndef __GUI_ACHIEVEMENTS
#define __GUI_ACHIEVEMENTS


namespace ach
{
	struct AchievementData
	{
		sf::Sprite *spr;
		sf::String  name;
		sf::String  desc;
	};


	struct Achievements
	{
		ach::AchievementData  data[ach::Achievement::acCount];
		ach::RectangleShape  *box;

		sf::Text             *text;
		sf::String            progress;
		sf::String            back;
		sf::Vector2f          pos;

		int  count;
		int  index;
		bool active;


		 Achievements();
		~Achievements();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void click(sf::Vector2f c);
		void move(int d);
		void quit();

		void init();
		void draw(int i, int y);
	};
}

#endif
