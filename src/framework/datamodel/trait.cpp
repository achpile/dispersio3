#include "meta/headers.hpp"


/***********************************************************************
     * json_dm_trait_process

***********************************************************************/
void json_dm_trait_process(json_t *obj, json_t *traits)
{
	json_t     *i;
	json_t     *list;
	const char *key;

	list = json_attr_get_traits(obj);

	if (list)
		json_dm_trait_add_list(obj, traits, list);

	json_object_foreach(obj, key, i)
	{
		if (!strcmp(key, DM_DIRECTIVE_ATTR))
			continue;

		if (json_is_object(i))
			json_dm_trait_process(i, traits);
	}
}



/***********************************************************************
     * json_dm_trait_process

***********************************************************************/
void json_dm_trait_add_list(json_t *obj, json_t *traits, json_t *list)
{
	if (!json_is_array(list))
	{
		logger->log(ach::LogLevel::llError, "Traits object should be an array");
		return;
	}

	json_t *t;
	json_t *trait;
	size_t  i;

	json_array_foreach(list, i, t)
	{
		if (!json_is_string(t))
		{
			logger->log(ach::LogLevel::llError, "Traits list contains wrong object");
			continue;
		}

		trait = json_object_get(traits, json_string_value(t));

		if (!trait)
		{
			logger->log(ach::LogLevel::llError, "Trait \"%s\" is not found", json_string_value(t));
			continue;
		}

		json_dm_trait_add(obj, trait);
	}
}



/***********************************************************************
     * json_dm_trait_process

***********************************************************************/
void json_dm_trait_add(json_t *obj, json_t *trait)
{
	json_t     *i;
	const char *key;

	json_object_foreach(trait, key, i)
		json_object_set(obj, key, i);
}
