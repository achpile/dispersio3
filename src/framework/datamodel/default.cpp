#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_generate_default

***********************************************************************/
json_t *json_dm_generate_default(json_t *obj, json_t *dm)
{
	json_t     *res;
	json_t     *i;
	const char *key;

	res = (obj) ? obj : json_object();

	json_object_foreach(dm, key, i)
	{
		if (!strcmp(key, DM_DIRECTIVE_ATTR))
			continue;


		switch (json_attr_get_type(i))
		{
			case ach::DataType::dtObject  : json_dm_generate_default_object(res, i, key); break;
			case ach::DataType::dtArray   : json_dm_generate_default_array (res, i, key); break;
			case ach::DataType::dtMulti   : json_dm_generate_default_multi (res, i, key); break;

			case ach::DataType::dtString  :
			case ach::DataType::dtInteger : 
			case ach::DataType::dtReal    :
			case ach::DataType::dtBoolean :
			case ach::DataType::dtFilename:
			case ach::DataType::dtColor   :
			case ach::DataType::dtLink    :
			case ach::DataType::dtEnum    :
			case ach::DataType::dtUnknown : json_dm_generate_default_value (res, i, key); break;
		}
	}

	return res;
}



/***********************************************************************
     * json_dm_generate_default_object

***********************************************************************/
void json_dm_generate_default_object(json_t *obj, json_t *dm, const char *key)
{
	json_t *existing;

	if (!json_object_get(obj, key))
		json_object_set_new_nocheck(obj, key, json_object());

	existing = json_object_get(obj, key);

	json_dm_generate_default(existing, dm);
}



/***********************************************************************
     * json_dm_generate_default_multi

***********************************************************************/
void json_dm_generate_default_multi(json_t *obj, json_t *dm, const char *key)
{
	json_t *existing;

	existing = json_object_get(obj, key);

	if (!existing)
	{
		json_object_set_new_nocheck(obj, key, json_object());
		return;
	}

	json_t     *instance;
	const char *name;

	json_object_foreach(existing, name, instance)
		json_dm_generate_default(instance, dm);
}



/***********************************************************************
     * json_dm_generate_default_array

***********************************************************************/
void json_dm_generate_default_array(json_t *obj, json_t *dm, const char *key)
{
	json_t *existing;

	if (!json_object_get(obj, key))
	{
		json_object_set_new_nocheck(obj, key, json_array());
		return;
	}

	existing = json_object_get(obj, key);

	json_t *instance;
	size_t  index;

	json_array_foreach(existing, index, instance)
		json_dm_generate_default(instance, dm);
}



/***********************************************************************
     * json_dm_generate_default_value

***********************************************************************/
void json_dm_generate_default_value(json_t *obj, json_t *dm, const char *key)
{
	if (!json_object_get(obj, key))
		json_object_set_new_nocheck(obj, key, json_attr_get_default(dm));
}
