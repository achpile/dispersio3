#include "meta/headers.hpp"


/***********************************************************************
     * Option
     * constructor

***********************************************************************/
ach::Option::Option(sf::String _caption, const char *_value)
{
	caption = _caption;

	strncpy(value, _value, STR_LEN_MENU);
}



/***********************************************************************
     * Option
     * destructor

***********************************************************************/
ach::Option::~Option()
{
}
