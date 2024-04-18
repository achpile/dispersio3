#include "meta/headers.hpp"


/***********************************************************************
     * text_align

***********************************************************************/
float text_align(sf::Text *text, float left, float width, ach::TextAlign align)
{
	switch (align)
	{
		case ach::TextAlign::taLeft  : return left;
		case ach::TextAlign::taCenter: return left + (width - text->getLocalBounds().width) / 2.0f;
		case ach::TextAlign::taRight : return left + (width - text->getLocalBounds().width);
	}

	return 0.0f;
}
