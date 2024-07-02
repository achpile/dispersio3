#include "meta/headers.hpp"


/***********************************************************************
     * DataSheet
     * constructor

***********************************************************************/
ach::DataSheet::DataSheet(json_t *obj)
{
	sheet = new ach::Sheet(json_object_get_string (obj, "Filename"),
	                       json_object_get_integer(obj, "Frames"  ),
	                       true);

	rate  = json_object_get_real(obj, "Rate");
}



/***********************************************************************
     * DataSheet
     * destructor

***********************************************************************/
ach::DataSheet::~DataSheet()
{
	delete sheet;
}
