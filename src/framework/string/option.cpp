#include "meta/headers.hpp"


/***********************************************************************
     * Option
     * constructor

***********************************************************************/
ach::Option::Option(json_t *obj)
{
	caption = "";
	token   = json_object_get_boolean(obj, "Token");
	value   = json_object_get        (obj, "Value");

	strncpy(name, json_object_get_string(obj, "Name"), STR_LEN_MENU);
}



/***********************************************************************
     * Option
     * destructor

***********************************************************************/
ach::Option::~Option()
{
}
