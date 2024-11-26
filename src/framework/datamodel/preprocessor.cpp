#include "meta/headers.hpp"


/***********************************************************************
     * json_preprocess

***********************************************************************/
json_t *json_preprocess(json_t *obj, const char *dir)
{
	json_t     *sub;
	const char *key;

	json_object_foreach(obj, key, sub)
	{
		if (json_is_object(sub))
			json_preprocess(sub, dir);

		if (json_is_string(sub))
		{
			const char *val = json_string_value(sub);

			if (*val == DM_DIRECTIVE_START)
			{
				json_t *res = json_preprocess_directive(val, dir);

				if (res)
				{
					json_object_set_new_nocheck(obj, key, res);
					json_decref(sub);
				}
				else
				{
					json_object_del(obj, key);
				}
			}
		}
	}

	return obj;
}



/***********************************************************************
     * json_preprocess_argument

***********************************************************************/
const char *json_preprocess_argument(const char *str)
{
	return strchr(str, ' ') + 1;
}



/***********************************************************************
     * json_preprocess_directive

***********************************************************************/
json_t *json_preprocess_directive(const char *name, const char *dir)
{
	if      (str_check_start(name, DM_DIRECTIVE_INCLUDE  )) return json_preprocess_include(json_preprocess_argument(name), dir);
	else if (str_check_start(name, DM_DIRECTIVE_DIR      )) return json_preprocess_dir    (json_preprocess_argument(name), dir, false);
	else if (str_check_start(name, DM_DIRECTIVE_RECURSIVE)) return json_preprocess_dir    (json_preprocess_argument(name), dir, true );

	else
		logger->log(ach::LogLevel::llError, "Unknown directive '%s'", name);

	return NULL;
}



/***********************************************************************
     * json_preprocess_include

***********************************************************************/
json_t *json_preprocess_include(const char *name, const char *dir)
{
	char path[STR_LEN_PATH];
	json_error_t error;

	if (name[0] == DM_DIRECTIVE_PWD)
	{
		name++;
		dir = ".";
	}

	snprintf(path, STR_LEN_PATH, "%s/%s", dir, name);

	logger->log(ach::LogLevel::llInfo, "Loading file: '%s'", path);

	if (!file_exists(path))
	{
		logger->log(ach::LogLevel::llError, "File not found: '%s'", path);
		return NULL;
	}

	json_t *res = json_load_file(path, 0, &error);

	if (!res)
	{
		logger->log(ach::LogLevel::llError, "Error loading file: '%s' (%s)", path, error.text);
		return NULL;
	}

	if (!json_is_object(res))
	{
		logger->log(ach::LogLevel::llError, "File has invalid format: '%s'", path);
		return NULL;
	}

	return json_preprocess(res, dirname(path));
}



/***********************************************************************
     * json_preprocess_dir

***********************************************************************/
json_t *json_preprocess_dir(const char *name, const char *dir, bool recursive)
{
	char path[STR_LEN_PATH];
	json_t *res;
	json_t *obj;

	snprintf(path, STR_LEN_PATH, "%s/%s", dir, name);

	if (!file_exists(path))
	{
		logger->log(ach::LogLevel::llError, "Directory not found: '%s'", path);
		return NULL;
	}

	obj = json_object();

	file_list(entry, path)
	{
		if (file_is_regular(entry))
		{
			res = json_preprocess_include(entry.path().filename().string().c_str(), path);
		}
		else if (recursive && file_is_directory(entry))
		{
			res = json_preprocess_dir(entry.path().filename().string().c_str(), path, true);
		}
		else
		{
			continue;
		}


		if (res)
		{
			json_merge(obj, json_preprocess(res, path));
			json_decref(res);
		}
	}

	return obj;
}
