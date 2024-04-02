#include "meta/headers.hpp"


/***********************************************************************
     * json_object_get_branch

***********************************************************************/
json_t *json_object_get_branch(json_t *root, const char *path)
{
	json_t *result = root;
	char   *k;
	char    p[STR_LEN_PATH];

	strncpy(p, path, STR_LEN_PATH);
	k = strtok(p, ".");


	while (k)
	{
		result = json_object_get(result, k);

		if (!result)
			return NULL;

		k = strtok(NULL, ".");
	}

	return result;
}



/***********************************************************************
     * json_object_set_branch

***********************************************************************/
void json_object_set_branch(json_t *root, const char *path, json_t *obj)
{
	json_t *parent;
	json_t *result = root;
	char   *k;

	char    p[STR_LEN_PATH];
	char    l[STR_LEN_PATH];

	strncpy(p, path, STR_LEN_PATH);
	k = strtok(p, ".");


	while (k)
	{
		parent = result;
		result = json_object_get(parent, k);

		if (!result)
		{
			result = json_object();
			json_object_set_new(parent, k, result);
		}

		strncpy(l, k, STR_LEN_PATH);

		k = strtok(NULL, ".");
	}

	json_object_set_new(parent, l, obj);
}
