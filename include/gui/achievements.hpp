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
		void move(int d);
		void back();

		void init();
		void draw(int i, int y);
	};
}

#endif
