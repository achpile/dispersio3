#include "meta/headers.hpp"


/***********************************************************************
     * json_attr_get_type_raw

***********************************************************************/
const char *json_attr_get_type_raw(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return NULL;
	}

	return json_object_get_string(attr, "type");
}



/***********************************************************************
     * json_attr_get_type

***********************************************************************/
ach::DataType json_attr_get_type(json_t *obj)
{
	const char *type = json_attr_get_type_raw(obj);

	if (!type)
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'type' in " DM_DIRECTIVE_ATTR " object", type);
		return ach::DataType::dtUnknown;
	}

	ach::DataType res = pair_get_enum(type, pairAttrType);

	if (res == ach::DataType::dtUnknown)
		logger->log(ach::LogLevel::llError, "Unknown type: '%s'", type);

	return res;
}



/***********************************************************************
     * json_attr_get_container

***********************************************************************/
bool json_attr_get_container(json_t *obj)
{
	switch (json_attr_get_type(obj))
	{
		case ach::DataType::dtObject  :
		case ach::DataType::dtArray   :
		case ach::DataType::dtMulti   : return true;

		case ach::DataType::dtString  :
		case ach::DataType::dtInteger :
		case ach::DataType::dtReal    :
		case ach::DataType::dtBoolean :
		case ach::DataType::dtFilename:
		case ach::DataType::dtColor   :
		case ach::DataType::dtLink    :
		case ach::DataType::dtEnum    :
		case ach::DataType::dtUnknown : return false;
	}

	return false;
}



/***********************************************************************
     * json_attr_get_default

***********************************************************************/
json_t *json_attr_get_default(json_t *obj)
{
	json_t *attr = json_object_get(obj, DM_DIRECTIVE_ATTR);

	if (!attr)
	{
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return NULL;
	}

	json_t *def = json_object_get(attr, "default");

	if (json_attr_get_type(obj) == ach::DataType::dtFilename)
	{
		char path[STR_LEN_PATH];

		snprintf(path, STR_LEN_PATH, DM_PATH_BASE "/%s", json_string_value(def));
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return 0;
	}

	if (!json_object_get(attr, "min"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'min' value in " DM_DIRECTIVE_ATTR "");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return 0;
	}

	if (!json_object_get(attr, "max"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'max' value in " DM_DIRECTIVE_ATTR "");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return 0;
	}

	if (!json_object_get(attr, "min"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'min' value in " DM_DIRECTIVE_ATTR "");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return 0;
	}

	if (!json_object_get(attr, "max"))
	{
		logger->log(ach::LogLevel::llError, "Cannot find 'max' value in " DM_DIRECTIVE_ATTR "");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
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
		logger->log(ach::LogLevel::llError, "Cannot find " DM_DIRECTIVE_ATTR " object");
		return NULL;
	}

	return json_object_get(attr, "enum");
}
