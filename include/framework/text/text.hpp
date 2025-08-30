#ifndef __FRAMEWORK_TEXT_TEXT
#define __FRAMEWORK_TEXT_TEXT


namespace ach
{
	struct Text
	{
		std::vector<sf::String> strings;
		std::vector<sf::String> words;

		ach::RenderLayer  layer;
		ach::TextAlign    align;
		sf::Text         *text;
		sf::String        string;
		sf::Vector2f      pos;

		float spacing;
		float width;


		 Text(sf::Font *font, int size);
		~Text();

		void render();

		void setString(sf::String _string);
		void setPosition(sf::Vector2f _pos);
		void setWidth(float _width);
		void setFont(sf::Font *font);
		void setSize(int size);
		void setColor(sf::Color color);
		void setSpacing(int _spacing);
		void setAlign(ach::TextAlign _align);
		void setLayer(ach::RenderLayer _layer);

		float height();

		void calc();
		void split();
		void merge();
	};
}

#endif
