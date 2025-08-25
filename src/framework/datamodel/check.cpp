#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_check_datatypes

***********************************************************************/
void json_dm_check_datatypes(json_t *obj, json_t *dm, const char *path)
{
	json_t     *i, *j;
	const char *key;

	json_object_foreach(obj, key, i)
	{
		j = json_object_get(dm, key);

		if (!j)
		{
			logger->log(ach::LogLevel::llWarning, "Object '%s' is not found in the datamodel", key);
			json_object_del(obj, key);
			continue;
		}

		if (!json_container_check(i, j, key, path))
		{
			json_object_del(obj, key);
			continue;
		}
	}
}



/***********************************************************************
     * json_dm_check_links

***********************************************************************/
void json_dm_check_links(json_t *data, json_t *obj, json_t *dm)
{
	json_t     *i, *j;
	const char *key;

	json_object_foreach(obj, key, i)
	{
		j = json_object_get(dm, key);


		if (json_attr_get_type(j) == ach::DataType::dtObject)
		{
			json_dm_check_links(data, i, j);
			continue;
		}


		if (json_attr_get_type(j) == ach::DataType::dtMulti)
		{
			json_t     *instance;
			const char *name;

			json_object_foreach(i, name, instance)
				json_dm_check_links(data, instance, j);

			continue;
		}


		if (json_attr_get_type(j) == ach::DataType::dtLink)
		{
			char path[STR_LEN_PATH];

			snprintf(path, STR_LEN_PATH, "%s.%s", json_attr_get_data(j), json_string_value(i));

			if (!json_object_get_branch(data, path))
			{
				logger->log(ach::LogLevel::llWarning, "Linked object '%s' is not found", path);
				json_string_set(i, json_string_value(json_attr_get_default(j)));
			}
		}
	}
}



/***********************************************************************
     * json_dm_check_classes

***********************************************************************/
void json_dm_check_classes(json_t *data, json_t *classes)
{
	json_t     *cls;
	const char *key;

	json_object_foreach(classes, key, cls)
		json_dm_class_check(data, cls);
}
