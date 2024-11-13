#include "meta/headers.hpp"


/***********************************************************************
     * DataFont
     * constructor

***********************************************************************/
ach::DataFont::DataFont(json_t *obj)
{
	sfml_load_font(&font, json_object_get_string(obj, "Filename"));
}



/***********************************************************************
     * DataFont
     * destructor

***********************************************************************/
ach::DataFont::~DataFont()
{
	delete font;
}
