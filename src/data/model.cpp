#include "meta/headers.hpp"


/***********************************************************************
     * DataModel
     * constructor

***********************************************************************/
ach::DataModel::DataModel(json_t *obj)
{
	type      = pair_get_enum(json_object_get_string(obj, "Type"), pairModel);
	sheet     = db->getSheet(json_object_get_string(obj, "Sheet"));
	animation = json_object_get(obj, "Animation");
}



/***********************************************************************
     * DataModel
     * destructor

***********************************************************************/
ach::DataModel::~DataModel()
{
}
