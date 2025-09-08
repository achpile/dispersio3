#include "meta/headers.hpp"


/***********************************************************************
     * text_draw

***********************************************************************/
void text_draw(sf::Text *text, sf::String str, float x, float y, float width, ach::TextAlign align, ach::RenderLayer layer)
{
	text->setString(str);
	text->setPosition(text_align(text, x, width, align), y);

	rm->draw(text, layer);
}



/***********************************************************************
     * text_draw

***********************************************************************/
void text_draw(sf::Text *text, sf::String str, float x, float y, float width, ach::TextAlign align, sf::RenderTarget *target)
{
	text->setString(str);
	text->setPosition(text_align(text, x, width, align), y);

	target->draw(*text);
}
