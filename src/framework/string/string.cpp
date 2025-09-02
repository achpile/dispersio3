#include "meta/headers.hpp"


/***********************************************************************
     * str_time

***********************************************************************/
sf::String str_time(float t)
{
	char result[STR_LEN_MENU];

	int l    = t * 1000;
	int msec = l % 1000; l /= 1000;
	int sec  = l % 60  ; l /= 60;
	int min  = l % 60  ; l /= 60;

	snprintf(result, STR_LEN_MENU, "%d:%02d:%02d.%03d", l, min, sec, msec);

	return sf::String(result);
}



/***********************************************************************
     * str_percent

***********************************************************************/
sf::String str_percent(int val, int count)
{
	if (!count)
		return sf::String("100%");

	return sf::String(std::to_string((val * 100) / count)) + "%";
}
