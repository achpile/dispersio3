#include "meta/headers.hpp"


/***********************************************************************
     * DataSheet
     * constructor

***********************************************************************/
ach::DataSheet::DataSheet(json_t *obj)
{
	sheet = new ach::Sheet(json_object_get_branch_string (obj, "Filename"),
	                       json_object_get_branch_integer(obj, "Frames"  ),
	                       true);
}



/***********************************************************************
     * DataSheet
     * destructor

***********************************************************************/
ach::DataSheet::~DataSheet()
{
	delete sheet;
}
