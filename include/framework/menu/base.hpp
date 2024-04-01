#ifndef __FRAMEWORK_MENU_BASE
#define __FRAMEWORK_MENU_BASE


namespace ach
{
	struct Menu
	{
		ach::MenuItem      *root;
		ach::MenuItem      *current;

		sf::RectangleShape *box;
		sf::Text           *text;
		sf::Vector2f        pos;
		sf::Vector2f        padding;

		float width;
		float spacing;
		int   height;
		int   size;


		 Menu();
		~Menu();

		void update();
		void render();

		void calculate();

		void setWidth(float _width);
		void setHeight(int _height);
		void setPosition(sf::Vector2f _pos);
		void setPadding(sf::Vector2f _padding);
		void setFontSize(int _size);
	};
}

#endif
