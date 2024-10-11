#include "meta/headers.hpp"


/***********************************************************************
     * sfml_load_font

***********************************************************************/
void sfml_load_font(sf::Font **font, const char *filename)
{
	(*font) = new sf::Font();

	if (!(*font)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading font: '%s'", filename);
}



/***********************************************************************
     * sfml_load_sound

***********************************************************************/
void sfml_load_sound(sf::SoundBuffer **sound, const char *filename)
{
	(*sound) = new sf::SoundBuffer();

	if (!(*sound)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading sound: '%s'", filename);
}



/***********************************************************************
     * sfml_load_image

***********************************************************************/
void sfml_load_image(sf::Image **image, const char *filename)
{
	(*image) = new sf::Image();

	if (!(*image)->loadFromFile(filename))
		logger->log(ach::LogLevel::llError, "Error loading image: '%s'", filename);
}
