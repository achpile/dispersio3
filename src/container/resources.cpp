#include "meta/headers.hpp"


/***********************************************************************
     * Resources
     * constructor

***********************************************************************/
ach::Resources::Resources()
{
	loadFont(&fonts.menu   , json_object_get_branch_string(dm->data, "Meta.Font.Menu"   ));
	loadFont(&fonts.credits, json_object_get_branch_string(dm->data, "Meta.Font.Credits"));

	loadSound(&sound.blip  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Blip"));
	loadSound(&sound.back  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Back"));
	loadSound(&sound.pick  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Pick"));

	loadImage(&meta.icon   , json_object_get_branch_string(dm->data, "Meta.Icon"));
}



/***********************************************************************
     * Resources
     * destructor

***********************************************************************/
ach::Resources::~Resources()
{
	delete fonts.menu;
	delete fonts.credits;

	delete sound.blip;
	delete sound.back;
	delete sound.pick;

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
     * loadSound

***********************************************************************/
void ach::Resources::loadSound(sf::SoundBuffer **sound, const char *filename)
{
	(*sound) = new sf::SoundBuffer();

	if (!(*sound)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading sound: \"%s\"", filename);
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
