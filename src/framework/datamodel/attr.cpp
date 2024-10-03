#include "meta/headers.hpp"


/***********************************************************************
     * json_get_type

***********************************************************************/
ach::JSONtype json_attr_get_type(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return ach::JSONtype::jtUnknown;
	}

	const char *type = json_object_get_string(attr, "type");

	if (!type)
	{
		logger->log(ach::LogLevel::llError, "Cannot find \"type\" in @attr object", type);
		return ach::JSONtype::jtUnknown;
	}

	ach::JSONtype res = (ach::JSONtype)pair_get_enum(type, pairAttrType);

	if (res == ach::JSONtype::jtUnknown)
		logger->log(ach::LogLevel::llError, "Unknown type: \"%s\"", type);

	return res;
}



/***********************************************************************
     * json_get_default

***********************************************************************/
json_t *json_attr_get_default(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return NULL;
	}

	json_t *def = json_object_get(attr, "default");

	if (json_attr_get_type(obj) == ach::jtFilename)
	{
		char path[STR_LEN_PATH];

		snprintf(path, STR_LEN_PATH, PATH_BASE "/%s", json_string_value(def));
		return json_string(path);
	}

	return json_deep_copy(def);
}



/***********************************************************************
     * json_attr_get_traits

***********************************************************************/
json_t *json_attr_get_traits(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return NULL;
	}

	return json_object_get(attr, "traits");
}



/***********************************************************************
     * json_attr_get_maxlen

***********************************************************************/
size_t json_attr_get_maxlen(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
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
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return 0;
	}

	if (!json_object_get(attr, "min"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'min' value in @attr");
		return 0;
	}

	return json_object_get_integer(attr, "min");
}



/***********************************************************************
     * json_attr_get_max

***********************************************************************/
int json_attr_get_max(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return 0;
	}

	if (!json_object_get(attr, "max"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'max' value in @attr");
		return 0;
	}

	return json_object_get_integer(attr, "max");
}



/***********************************************************************
     * json_attr_get_min_real

***********************************************************************/
float json_attr_get_min_real(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return 0;
	}

	if (!json_object_get(attr, "min"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'min' value in @attr");
		return 0;
	}

	return json_object_get_real(attr, "min");
}



/***********************************************************************
     * json_attr_get_max_real

***********************************************************************/
float json_attr_get_max_real(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return 0;
	}

	if (!json_object_get(attr, "max"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'max' value in @attr");
		return 0;
	}

	return json_object_get_real(attr, "max");
}



/***********************************************************************
     * json_attr_get_data

***********************************************************************/
const char *json_attr_get_data(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return NULL;
	}

	return json_object_get_string(attr, "data");
}



/***********************************************************************
     * json_attr_get_enum

***********************************************************************/
json_t *json_attr_get_enum(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find @attr object");
		return NULL;
	}

	return json_object_get(attr, "enum");
}
