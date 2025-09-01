#ifndef __GUI_STATUS
#define __GUI_STATUS


namespace ach
{
	struct Status
	{
		std::vector<ach::Statistic*> lines;

		ach::RectangleShape *box;
		sf::Text            *text;

		sf::Vector2f         pos;

		float width;
		float spacing;


		 Status();
		~Status();

		void update();
		void render();

		void style();
		void translate();
	};
}

#endif
