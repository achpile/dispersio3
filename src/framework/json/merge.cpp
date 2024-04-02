#include "meta/headers.hpp"


/***********************************************************************
     * json_merge

***********************************************************************/
void json_merge(json_t *parent, json_t *obj)
{
	json_t     *existing;
	json_t     *i;
	const char *entry;

	json_object_foreach(obj, entry, i)
	{
		existing = json_object_get(parent, entry);

		if (!existing)
		{
			json_object_set(parent, entry, i);
			continue;
		}

		if (json_is_array(i))
			json_array_extend(existing, i);
		else if (json_is_object(i))
			json_merge(existing, i);
		else
			json_object_set(parent, entry, i);
	}
}
