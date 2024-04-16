#ifndef __FRAMEWORK_MENU_BASE
#define __FRAMEWORK_MENU_BASE


namespace ach
{
	struct Menu
	{
		std::vector<ach::MenuItem*> items;

		ach::MenuItemFolder *root;
		ach::MenuItemFolder *current;

		sf::RectangleShape  *box;
		sf::Text            *text;
		sf::Vector2f         pos;
		sf::Vector2f         padding;

		float width;
		float spacing;
		float offset;

		bool  isActive;

		int   height;
		int   size;
		int   index;


		 Menu(const char *name);
		~Menu();

		void update();
		void render();

		void controls();

		void add(const char *_parent, ach::MenuItem *item);
		void go(ach::MenuItemFolder *parent, ach::MenuItem *item);

		bool inside(sf::Vector2f pos);
		void hover(sf::Vector2f pos);
		void click(sf::Vector2f pos, bool left);

		void finalize();
		void translate();
		void calculate();

		void setWidth(float _width);
		void setHeight(int _height);
		void setPosition(sf::Vector2f _pos);
		void setPadding(sf::Vector2f _padding);
		void setFontSize(int _size);

		void print(sf::String string, float x, int y, ach::TextAlign align);
		void printItem(sf::String string, int y);
		void printCaption();
		void printSelector();
	};
}

#endif
