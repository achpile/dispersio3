#include "meta/headers.hpp"


/***********************************************************************
     * DataSheet
     * constructor

***********************************************************************/
ach::DataSheet::DataSheet(const char *_name, json_t *obj)
{
	strncpy(name, _name, STR_LEN_NAME);

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
