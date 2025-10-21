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
		ach::AchievementData data[ach::Achievement::acCount];

		bool active;


		 Achievements();
		~Achievements();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style();

		void controls();
		void init();
	};
}

#endif
