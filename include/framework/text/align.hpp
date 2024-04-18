#ifndef __FRAMEWORK_TEXT_ALIGN
#define __FRAMEWORK_TEXT_ALIGN


namespace ach
{
	enum TextAlign
	{
		taLeft,
		taCenter,
		taRight
	};
}

float text_align(sf::Text *text, float left, float width, ach::TextAlign align);

#endif
