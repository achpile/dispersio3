#include "meta/headers.hpp"


/***********************************************************************
     * DataMap
     * constructor

***********************************************************************/
ach::DataMap::DataMap(json_t *obj)
{
	parallax = db->getParallax(json_object_get_string(obj, "Background"));
	spawn    = vector_json_tile(json_object_get(obj, "Spawn"));
	stars    = json_object_get_boolean(obj, "Stars");

	strncpy(filename, json_object_get_string(obj, "Filename"), STR_LEN_PATH);
}



/***********************************************************************
     * DataMap
     * destructor

***********************************************************************/
ach::DataMap::~DataMap()
{
}
