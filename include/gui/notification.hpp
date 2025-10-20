#ifndef __GUI_NOTIFICATION
#define __GUI_NOTIFICATION


namespace ach
{
	struct Notification
	{
		std::vector<ach::Achievement> list;

		ach::RectangleShape *box;
		ach::DataSound      *sfx;
		ach::Sprite         *spr;
		ach::Timer           timer;

		sf::Text            *text;
		sf::String           caption;
		sf::String           name;
		sf::Vector2f         pos;
		sf::Vector2f         offset;


		 Notification();
		~Notification();

		void update();
		void render();

		void style();
		void translate();

		void init();
		void next();
		void trigger(ach::Achievement achievement);
	};
}

#endif
