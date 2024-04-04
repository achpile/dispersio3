#include "meta/headers.hpp"


/***********************************************************************
     * json_get_type

***********************************************************************/
ach::JSONtype json_attr_get_type(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return ach::JSONtype::jtUnknown;
	}

	const char *type = json_object_get_string(attr, "type");

	if (!type)
	{
		logger->log(ach::LogLevel::llError, "Cannot find \"type\" in #attr object", type);
		return ach::JSONtype::jtUnknown;
	}

	     if (!strcmp(type, "object"  )) return ach::JSONtype::jtObject;
	else if (!strcmp(type, "string"  )) return ach::JSONtype::jtString;
	else if (!strcmp(type, "integer" )) return ach::JSONtype::jtInteger;
	else if (!strcmp(type, "boolean" )) return ach::JSONtype::jtBoolean;
	else if (!strcmp(type, "filename")) return ach::JSONtype::jtFilename;
	else if (!strcmp(type, "color"   )) return ach::JSONtype::jtColor;
	else if (!strcmp(type, "array"   )) return ach::JSONtype::jtArray;
	else if (!strcmp(type, "multi"   )) return ach::JSONtype::jtMulti;
	else if (!strcmp(type, "link"    )) return ach::JSONtype::jtLink;

	logger->log(ach::LogLevel::llError, "Unknown type: \"%s\"", type);
	return ach::JSONtype::jtUnknown;
}



/***********************************************************************
     * json_get_default

***********************************************************************/
json_t *json_attr_get_default(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return NULL;
	}

	json_t *def = json_object_get(attr, "default");

	if (json_attr_get_type(obj) == ach::JSONtype::jtFilename)
	{
		char path[STR_LEN_PATH];

		snprintf(path, STR_LEN_PATH, "%s/%s", json_attr_get_dir(obj), json_string_value(def));
		return json_string(path);
	}

	return json_deep_copy(def);
}



/***********************************************************************
     * json_attr_get_maxlen

***********************************************************************/
size_t json_attr_get_maxlen(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return STR_LEN_NAME;
	}

	if (!json_object_get(attr, "maxlen"))
		return STR_LEN_NAME;

	return json_object_get_integer(attr, "maxlen");
}



/***********************************************************************
     * json_attr_get_min

***********************************************************************/
int json_attr_get_min(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return 0;
	}

	if (!json_object_get(attr, "min"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'min' value in #attr");
		return 0;
	}

	return json_object_get_integer(attr, "min");
}



/***********************************************************************
     * json_attr_get_max

***********************************************************************/
int json_attr_get_max(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return 0;
	}

	if (!json_object_get(attr, "max"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'max' value in #attr");
		return 0;
	}

	return json_object_get_integer(attr, "max");
}



/***********************************************************************
     * json_attr_get_dir

***********************************************************************/
const char *json_attr_get_dir(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return NULL;
	}

	return json_object_get_string(attr, "dir");
}



/***********************************************************************
     * json_attr_get_data

***********************************************************************/
const char *json_attr_get_data(json_t *obj)
{
	json_t *attr = json_object_get(obj, "#attr");

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find #attr object");
		return NULL;
	}

	return json_object_get_string(attr, "data");
}
