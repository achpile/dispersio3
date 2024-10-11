#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_class_check

***********************************************************************/
void json_dm_class_check(json_t *data, json_t *cls)
{
	json_t *multi = json_object_get_branch(data, json_object_get_string(cls, "Path"));

	if (!multi)
		return;

	json_t     *obj;
	const char *key;

	json_object_foreach(multi, key, obj)
		json_dm_class_check_object(obj, cls);
}



/***********************************************************************
     * json_dm_class_check_object

***********************************************************************/
void json_dm_class_check_object(json_t *obj, json_t *cls)
{
	if (!json_equal(json_object_get(cls, "Value"), json_object_get(obj, json_object_get_string(cls, "Param"))))
		return;

	size_t      i;
	const char *key;
	const char *list = json_object_get_string(cls, "List");
	json_t     *j;
	json_t     *multi = json_object_get(obj, list);


	json_array_foreach(json_object_get(cls, "Objects"), i, j)
	{
		key = json_string_value(j);
		if (!json_object_get(multi, key))
		{
			logger->log(ach::LogLevel::llError, "Object missing '%s' in '%s'", key, list);
			json_object_set_new(multi, key, json_object());
		}
	}


	json_object_foreach(multi, key, j)
	{
		if (!json_array_contains(json_object_get(cls, "Objects"), key))
		{
			logger->log(ach::LogLevel::llError, "Object should not have '%s' in '%s'", key, list);
			json_object_del(multi, key);
		}
	}
}
