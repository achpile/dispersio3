#include "meta/headers.hpp"


/***********************************************************************
     * str_to_color

***********************************************************************/
sf::Color str_to_color(const char *str)
{
	sf::Color c;

	if (strlen(str) == 7)
		sscanf(str, "#%02hhx%02hhx%02hhx", &c.r, &c.g, &c.b);
	else
		sscanf(str, "#%02hhx%02hhx%02hhx%02hhx", &c.r, &c.g, &c.b, &c.a);

	return c;
}
