#ifndef __GUI_MESSAGE
#define __GUI_MESSAGE


namespace ach
{
	struct Message
	{
		ach::RectangleShape *box;
		ach::Text           *text;

		float width;
		float spacing;


		 Message(float _width = 0.0f);
		~Message();

		void update();
		void render();

		void style();

		void setString(sf::String string);
		void setPosition(sf::Vector2f pos);
		void setWidth(float _width);
	};
}

#endif
