#include "meta/headers.hpp"


/***********************************************************************
     * DataFont
     * constructor

***********************************************************************/
ach::DataFont::DataFont(json_t *obj)
{
	sfml_load_font(&font, json_string_value(obj));
}



/***********************************************************************
     * DataFont
     * destructor

***********************************************************************/
ach::DataFont::~DataFont()
{
	delete font;
}
