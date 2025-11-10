#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_check_datatypes

***********************************************************************/
void json_dm_check_datatypes(json_t *obj, json_t *dm, const char *path)
{
	json_t     *i, *j;
	json_t     *copy = json_deep_copy(obj);
	const char *key;

	json_object_foreach(copy, key, i)
	{
		j = json_object_get(dm, key);

		if (!j)
		{
			logger->log(ach::LogLevel::llWarning, "Object '%s' is not found in the datamodel", key);
			json_object_del(obj, key);
			continue;
		}

		if (!json_container_check(json_object_get(obj, key), j, key, path))
		{
			json_object_del(obj, key);
			continue;
		}
	}

	json_decref(copy);
}



/***********************************************************************
     * json_dm_check_links

***********************************************************************/
void json_dm_check_links(json_t *data, json_t *obj, json_t *dm)
{
	json_t     *instance;
	const char *key;

	json_object_foreach(obj, key, instance)
		json_dm_check_links_container(data, instance, json_object_get(dm, key));
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
