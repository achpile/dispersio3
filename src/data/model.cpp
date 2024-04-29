#include "meta/headers.hpp"


/***********************************************************************
     * DataModel
     * constructor

***********************************************************************/
ach::DataModel::DataModel(const char *_name, json_t *obj)
{
	strncpy(name, _name, STR_LEN_NAME);

	animation = json_object_get(obj, "Animation");
	sheet     = db->getSheet(json_object_get_string(obj, "Sheet"));
}



/***********************************************************************
     * DataModel
     * destructor

***********************************************************************/
ach::DataModel::~DataModel()
{
}
