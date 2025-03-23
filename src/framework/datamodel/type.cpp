#include "meta/headers.hpp"


/***********************************************************************
     * json_type_check

***********************************************************************/
bool json_type_check(json_t *obj, json_t *dm, const char *name, const char *path)
{
	switch (json_attr_get_type(dm))
	{
		case ach::DataType::dtObject  : return json_type_check_object  (obj, dm, name, path);
		case ach::DataType::dtString  : return json_type_check_string  (obj, dm, name, path);
		case ach::DataType::dtInteger : return json_type_check_integer (obj, dm, name, path);
		case ach::DataType::dtReal    : return json_type_check_real    (obj, dm, name, path);
		case ach::DataType::dtBoolean : return json_type_check_boolean (obj, dm, name, path);
		case ach::DataType::dtFilename: return json_type_check_filename(obj, dm, name, path);
		case ach::DataType::dtColor   : return json_type_check_color   (obj, dm, name, path);
		case ach::DataType::dtArray   : return json_type_check_array   (obj, dm, name, path);
		case ach::DataType::dtMulti   : return json_type_check_multi   (obj, dm, name, path);
		case ach::DataType::dtLink    : return json_type_check_link    (obj, dm, name, path);
		case ach::DataType::dtEnum    : return json_type_check_enum    (obj, dm, name, path);
		case ach::DataType::dtUnknown : return false;
	}

	return false;
}



/***********************************************************************
     * json_type_check_object

***********************************************************************/
bool json_type_check_object(json_t *obj, json_t *dm, const char *name, const char *path)
{
	if (!json_is_object(obj))
	{
		logger->log(ach::LogLevel::llError, "Value '%s' should be object", name);
		return false;
	}

	json_dm_check_datatypes(obj, dm, path);

	return true;
}



/***********************************************************************
     * json_type_check_string

***********************************************************************/
bool json_type_check_string(json_t *obj, json_t *dm, const char *name, const char *)
{
	if (!json_is_string(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a string", name);
		return false;
	}

	if (str_utf8_len(json_string_value(obj)) >= json_attr_get_maxlen(dm))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is too long", name);
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_integer

***********************************************************************/
bool json_type_check_integer(json_t *obj, json_t *dm, const char *name, const char *)
{
	if (!json_is_integer(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be an integer", name);
		return false;
	}

	if (json_integer_value(obj) < json_attr_get_min(dm))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is less than minimum (%d < %d)", name, json_integer_value(obj), json_attr_get_min(dm));
		return false;
	}

	if (json_integer_value(obj) > json_attr_get_max(dm))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is more than maximum (%d > %d)", name, json_integer_value(obj), json_attr_get_max(dm));
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_real

***********************************************************************/
bool json_type_check_real(json_t *obj, json_t *dm, const char *name, const char *)
{
	if (!json_is_number(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a real number", name);
		return false;
	}

	if (json_number_value(obj) < json_attr_get_min_real(dm))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is less than minimum (%f < %f)", name, json_number_value(obj), json_attr_get_min_real(dm));
		return false;
	}

	if (json_number_value(obj) > json_attr_get_max_real(dm))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is more than maximum (%f > %f)", name, json_number_value(obj), json_attr_get_max_real(dm));
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_boolean

***********************************************************************/
bool json_type_check_boolean(json_t *obj, json_t *, const char *name, const char *)
{
	if (!json_is_boolean(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be boolean", name);
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_filename

***********************************************************************/
bool json_type_check_filename(json_t *obj, json_t *, const char *name, const char *path)
{
	char filename[STR_LEN_PATH];

	if (!json_is_string(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a filename", name);
		return false;
	}

	snprintf(filename, STR_LEN_PATH, "%s/%s", path, json_string_value(obj));

	if (!file_exists(filename))
	{
		logger->log(ach::LogLevel::llWarning, "File '%s' is not found: using %s dir instead", filename, DM_PATH_BASE);

		snprintf(filename, STR_LEN_PATH, "%s/%s", DM_PATH_BASE, json_string_value(obj));
	}

	if (!file_exists(filename))
	{
		logger->log(ach::LogLevel::llWarning, "File '%s' is also not found", filename);
		return false;
	}

	json_string_set(obj, filename);
	return true;
}



/***********************************************************************
     * json_type_check_array

***********************************************************************/
bool json_type_check_array(json_t *obj, json_t *dm, const char *name, const char *path)
{
	if (!json_is_array(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be an array", name);
		return false;
	}

	size_t  i;
	json_t *j;

	json_array_foreach(obj, i, j)
	{
		if (!json_is_object(j))
		{
			logger->log(ach::LogLevel::llWarning, "Item [%zu] of array '%s' is not an object", i, name);
			json_array_remove(obj, i);
			continue;
		}

		json_dm_check_datatypes(j, dm, path);
	}

	return true;
}



/***********************************************************************
     * json_type_check_multi

***********************************************************************/
bool json_type_check_multi(json_t *obj, json_t *dm, const char *name, const char *path)
{
	if (!json_is_object(obj))
	{
		logger->log(ach::LogLevel::llError, "Value '%s' should be object", name);
		return false;
	}

	const char *key;
	json_t     *instance;

	json_object_foreach(obj, key, instance)
	{
		if (strlen(key) >= STR_LEN_NAME)
		{
			logger->log(ach::LogLevel::llError, "Name is too long: '%s'", key);
			json_object_del(obj, key);
			continue;
		}

		if (!str_check_regex(key, STR_REGEX_NAME))
		{
			logger->log(ach::LogLevel::llError, "Name has wrong symbols: '%s'", key);
			json_object_del(obj, key);
			continue;
		}

		json_dm_check_datatypes(instance, dm, path);
	}

	return true;
}



/***********************************************************************
     * json_type_check_color

***********************************************************************/
bool json_type_check_color(json_t *obj, json_t *, const char *name, const char *)
{
	if (!json_is_string(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a color", name);
		return false;
	}

	if (!str_check_regex(json_string_value(obj), STR_REGEX_COLOR))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' has wrong format (%s)", name, json_string_value(obj));
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_link

***********************************************************************/
bool json_type_check_link(json_t *obj, json_t *, const char *name, const char *)
{
	if (!json_is_string(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a link", name);
		return false;
	}

	if (strlen(json_string_value(obj)) >= STR_LEN_NAME)
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is too long", name);
		return false;
	}

	if (!str_check_regex(json_string_value(obj), STR_REGEX_NAME))
	{
		logger->log(ach::LogLevel::llError, "Value '%s' has wrong symbols: '%s'", name, json_string_value(obj));
		return false;
	}

	return true;
}



/***********************************************************************
     * json_type_check_enum

***********************************************************************/
bool json_type_check_enum(json_t *obj, json_t *dm, const char *name, const char *)
{
	if (!json_is_string(obj))
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' must be a link", name);
		return false;
	}

	if (strlen(json_string_value(obj)) >= STR_LEN_NAME)
	{
		logger->log(ach::LogLevel::llWarning, "Value '%s' is too long", name);
		return false;
	}

	if (!str_check_regex(json_string_value(obj), STR_REGEX_NAME))
	{
		logger->log(ach::LogLevel::llError, "Value '%s' has wrong symbols: '%s'", name, json_string_value(obj));
		return false;
	}

	size_t  index;
	json_t *item;

	json_array_foreach(json_attr_get_enum(dm), index, item)
		if (!strcmp(json_string_value(obj), json_string_value(item)))
			return true;

	logger->log(ach::LogLevel::llError, "Value '%s' is not in the enum list: %s", name, json_string_value(obj));
	return false;
}
