#ifndef __FRAMEWORK_MENU_BASE
#define __FRAMEWORK_MENU_BASE


namespace ach
{
	struct Menu
	{
		std::vector<ach::MenuItem*> items;

		ach::MenuItemFolder  *root;
		ach::MenuItemFolder  *current;
		ach::MenuItemControl *binding;

		ach::MenuTheme       *theme;

		sf::SoundBuffer      *sfxBlip;
		sf::SoundBuffer      *sfxBack;
		sf::SoundBuffer      *sfxPick;

		sf::RectangleShape   *box;
		sf::Text             *text;
		sf::Vector2f          pos;
		sf::Vector2f          padding;

		float  width;
		float  height;
		float  spacing;
		float  offset;

		bool   enabled;
		void  *context;

		int    lines;
		int    index;


		 Menu(void *_context, ach::MenuTheme *_theme);
		~Menu();

		void update();
		void render();

		void event(sf::Event e);

		void translate();
		void style(ach::MenuTheme *_theme);

		/*  base/controls.cpp  */
		void controls();
		bool inside(sf::Vector2f pos);
		void hover(sf::Vector2f pos);
		void click(sf::Vector2f pos, bool left);
		void select(int i);
		void move(int d);

		/*  base/items.cpp  */
		void init(const char *_root);
		void add(const char *_parent, ach::MenuItem *item);
		void go(ach::MenuItemFolder *parent, ach::MenuItem *item);

		void clear();
		void reset();
		void finalize();

		/*  base/dimensions.cpp  */
		float left();
		float right();
		float top();
		float line(int l);
		void  calculate();

		/*  base/set.cpp  */
		void setWidth(float _width);
		void setWidthE(float _width);
		void setHeight(int _height);
		void setHeightE(float _height);
		void setPosition(sf::Vector2f _pos);
		void setPadding(sf::Vector2f _padding);

		/*  base/print.cpp  */
		void print(sf::String string, float x, int y, ach::TextAlign align);
		void printItem(sf::String string, int y);
		void printCaption();
		void printSelector();
	};
}

#endif
