#include "meta/headers.hpp"


/***********************************************************************
     * json_property_get

***********************************************************************/
json_t* json_property_get(json_t *obj, const char *name)
{
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(obj, "properties"), index, item)
		if (!strcmp(name, json_object_get_string(item, "name")))
			return json_object_get(item, "value");

	logger->log(ach::LogLevel::llError, "JSON property \"%s\" is not found", name);
	return NULL;
}
