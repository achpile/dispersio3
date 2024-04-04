#include "meta/headers.hpp"


/***********************************************************************
     * Resources
     * constructor

***********************************************************************/
ach::Resources::Resources()
{
	loadFont(&fonts.base, "data/fonts/dejavu.ttf");
}



/***********************************************************************
     * Resources
     * destructor

***********************************************************************/
ach::Resources::~Resources()
{
	delete fonts.base;
}



/***********************************************************************
     * Resources
     * loadFont

***********************************************************************/
void ach::Resources::loadFont(sf::Font **font, const char *filename)
{
	(*font) = new sf::Font();

	if (!(*font)->loadFromFile(filename))
	{
		logger->log(ach::llError, "Error loading font: \"%s\"", filename);
		return;
	}
}
