#include "meta/headers.hpp"


/***********************************************************************
     * DataModel
     * constructor

***********************************************************************/
ach::DataModel::DataModel(const char *_name, json_t *obj)
{
	strncpy(name, _name, STR_LEN_NAME);

	animation = json_object_get(obj, "Animation");
	sheet     = new ach::Sheet(json_object_get_branch_string (obj, "Sheet.Filename"),
	                           json_object_get_branch_integer(obj, "Sheet.Frames"  ),
	                           true);
}



/***********************************************************************
     * DataModel
     * destructor

***********************************************************************/
ach::DataModel::~DataModel()
{
	delete sheet;
}
