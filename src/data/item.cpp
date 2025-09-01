#include "meta/headers.hpp"


/***********************************************************************
     * DataItem
     * constructor

***********************************************************************/
ach::DataItem::DataItem(json_t *obj)
{
	sheet        = db->getSheet(json_object_get_string(obj, "Sheet"));
	category     = pair_get_enum(json_object_get_string(obj, "Category"), pairCategory);

	strncpy(flag, json_object_get_string(obj, "Flag"), STR_LEN_NAME);
}



/***********************************************************************
     * DataItem
     * destructor

***********************************************************************/
ach::DataItem::~DataItem()
{
}
