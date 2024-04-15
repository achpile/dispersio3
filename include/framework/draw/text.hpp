#ifndef __FRAMEWORK_DRAW_TEXT
#define __FRAMEWORK_DRAW_TEXT


namespace ach
{
	enum TextAlign
	{
		taLeft,
		taCenter,
		taRight
	};
}


void textDraw(sf::Text *text, sf::String str, float x, float y, float width, ach::TextAlign align, ach::RenderLayer layer);

#endif
