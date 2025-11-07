#include "meta/headers.hpp"


/***********************************************************************
     * json_container_check

***********************************************************************/
bool json_container_check(json_t *obj, json_t *dm, const char *name, const char *path)
{
	switch (json_attr_get_container(dm))
	{
		case ach::ContainerType::ctSimple : return json_container_check_simple(obj, dm, name, path);
		case ach::ContainerType::ctArray  : return json_container_check_array (obj, dm, name, path);
		case ach::ContainerType::ctMulti  : return json_container_check_multi (obj, dm, name, path);
		case ach::ContainerType::ctUnknown: return false;
	}

	return false;
}



/***********************************************************************
     * json_container_check_simple

***********************************************************************/
bool json_container_check_simple(json_t *obj, json_t *dm, const char *name, const char *path)
{
	return json_type_check(obj, dm, name, path);
}



/***********************************************************************
     * json_container_check_array

***********************************************************************/
bool json_container_check_array(json_t *obj, json_t *dm, const char *name, const char *path)
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
		if (!json_type_check(j, dm, name, path))
		{
			logger->log(ach::LogLevel::llWarning, "Item [%zu] of array '%s' has wrong type", i, name);
			json_array_remove(obj, i);
		}
	}

	return true;
}



/***********************************************************************
     * json_container_check_multi

***********************************************************************/
bool json_container_check_multi(json_t *obj, json_t *dm, const char *name, const char *path)
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

		if (!str_check_name(key))
		{
			logger->log(ach::LogLevel::llError, "Name has wrong symbols: '%s'", key);
			json_object_del(obj, key);
			continue;
		}

		if (!json_type_check(instance, dm, key, path))
			json_object_del(obj, key);
	}

	return true;
}
