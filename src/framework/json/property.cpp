#include "meta/headers.hpp"


/***********************************************************************
     * json_property

***********************************************************************/
bool json_property(json_t *obj, const char *name)
{
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(obj, "properties"), index, item)
		if (!strcmp(name, json_object_get_string(item, "name")))
			return true;

	return false;
}



/***********************************************************************
     * json_class

***********************************************************************/
bool json_class(json_t *obj, const char *name)
{
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(obj, "properties"), index, item)
		if (!strcmp(name, json_object_get_string(item, "name")))
			return true;

	return false;
}



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

	logger->log(ach::LogLevel::llError, "JSON property '%s' is not found", name);
	return NULL;
}



/***********************************************************************
     * json_class_get

***********************************************************************/
json_t* json_class_get(json_t *obj, const char *name, const char *value)
{
	json_t *item;
	size_t  index;

	json_array_foreach(json_object_get(obj, "properties"), index, item)
		if (!strcmp(name, json_object_get_string(item, "name")))
			return json_object_get(json_object_get(item, "value"), value);

	logger->log(ach::LogLevel::llError, "JSON class '%s' value '%s' is not found", name, value);
	return NULL;
}
