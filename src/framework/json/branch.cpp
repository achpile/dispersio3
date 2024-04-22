#include "meta/headers.hpp"


/***********************************************************************
     * json_object_get_branch

***********************************************************************/
json_t *json_object_get_branch(json_t *root, const char *path)
{
	if (!path)
	{
		logger->log(ach::LogLevel::llError, "json_object_get_branch: path is NULL");
		return NULL;
	}

	if (!root)
	{
		logger->log(ach::LogLevel::llError, "json_object_get_branch: root object is NULL");
		return NULL;
	}

	if (strlen(path) >= STR_LEN_PATH)
	{
		logger->log(ach::LogLevel::llError, "json_object_get_branch: path is too long");
		return NULL;
	}


	json_t *result = root;
	char   *k;
	char    p[STR_LEN_PATH];

	strncpy(p, path, STR_LEN_PATH);
	k = strtok(p, ".");


	while (k)
	{
		result = json_object_get(result, k);

		if (!result)
		{
			logger->log(ach::LogLevel::llError, "json_object_get_branch: object not found \"%s\"", path);
			return NULL;
		}

		k = strtok(NULL, ".");
	}

	return result;
}



/***********************************************************************
     * json_object_set_branch

***********************************************************************/
void json_object_set_branch(json_t *root, const char *path, json_t *obj)
{
	if (!path)
	{
		logger->log(ach::LogLevel::llError, "json_object_set_branch: path is NULL");
		return;
	}

	if (!root)
	{
		logger->log(ach::LogLevel::llError, "json_object_set_branch: root object is NULL");
		return;
	}

	if (!obj)
	{
		logger->log(ach::LogLevel::llError, "json_object_set_branch: new object is NULL");
		return;
	}

	if (strlen(path) >= STR_LEN_PATH)
	{
		logger->log(ach::LogLevel::llError, "json_object_set_branch: path is too long");
		return;
	}


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



/***********************************************************************
     * json_object_getv_branch

***********************************************************************/
json_t *json_object_getv_branch(json_t *root, const char *format, ...)
{
	char path[STR_LEN_PATH];

	va_list ap;

	va_start(ap, format);
	vsnprintf(path, STR_LEN_PATH, format, ap);
	va_end(ap);

	return json_object_get_branch(root, path);
}



/***********************************************************************
     * json_object_setv_branch

***********************************************************************/
void json_object_setv_branch(json_t *root, json_t *obj, const char *format, ...)
{
	char path[STR_LEN_PATH];

	va_list ap;

	va_start(ap, format);
	vsnprintf(path, STR_LEN_PATH, format, ap);
	va_end(ap);

	json_object_set_branch(root, path, obj);
}
