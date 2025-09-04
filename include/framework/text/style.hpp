#ifndef __FRAMEWORK_TEXT_STYLE
#define __FRAMEWORK_TEXT_STYLE


namespace ach
{
	struct TextStyle
	{
		sf::Font        *font;
		sf::Color        color;

		int              size;


		 TextStyle();
		~TextStyle();

		int spacing();
	};
}

#endif
