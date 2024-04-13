#include "meta/headers.hpp"


/***********************************************************************
     * Resources
     * constructor

***********************************************************************/
ach::Resources::Resources()
{
	loadFont(&fonts.base, json_object_get_branch_string(dm->data, "Meta.Font.Base"));

	loadImage(&meta.icon, json_object_get_branch_string(dm->data, "Meta.Icon"));
}



/***********************************************************************
     * Resources
     * destructor

***********************************************************************/
ach::Resources::~Resources()
{
	delete fonts.base;

	delete meta.icon;
}



/***********************************************************************
     * Resources
     * loadFont

***********************************************************************/
void ach::Resources::loadFont(sf::Font **font, const char *filename)
{
	(*font) = new sf::Font();

	if (!(*font)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading font: \"%s\"", filename);
}



/***********************************************************************
     * Resources
     * loadImage

***********************************************************************/
void ach::Resources::loadImage(sf::Image **image, const char *filename)
{
	(*image) = new sf::Image();

	if (!(*image)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading image: \"%s\"", filename);
}
