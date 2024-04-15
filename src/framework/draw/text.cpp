#include "meta/headers.hpp"


/***********************************************************************
     * textDraw

***********************************************************************/
void textDraw(sf::Text *text, sf::String str, float x, float y, float width, ach::TextAlign align, ach::RenderLayer layer)
{
	text->setString(str);

	switch (align)
	{
		case ach::TextAlign::taLeft:
			text->setPosition(x, y);
			break;

		case ach::TextAlign::taCenter:
			text->setPosition(x + (width - text->getLocalBounds().width) / 2.0f, y);
			break;

		case ach::TextAlign::taRight:
			text->setPosition(x + (width - text->getLocalBounds().width), y);
			break;
	}

	rm->draw(text, layer);
}
