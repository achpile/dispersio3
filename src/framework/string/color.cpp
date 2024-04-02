#include "meta/headers.hpp"


/***********************************************************************
     * str_to_color

***********************************************************************/
sf::Color str_to_color(const char *str)
{
	sf::Color     c;

	if (strlen(str) == 7)
		sscanf(str, "#%02hhx%02hhx%02hhx", &c.r, &c.g, &c.b);
	else
		sscanf(str, "#%02hhx%02hhx%02hhx%02hhx", &c.r, &c.g, &c.b, &c.a);

	return c;
}



/***********************************************************************
     * str_is_color_correct

***********************************************************************/
bool str_is_color_correct(const char *str)
{
	if (strlen(str) != 7 && strlen(str) != 9)
		return false;

	if (str[0] != '#')
		return false;

	for (size_t i = 1; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;

		if (str[i] >= 'a' && str[i] <= 'f')
			continue;

		if (str[i] >= 'A' && str[i] <= 'F')
			continue;

		return false;
	}

	return true;
}
