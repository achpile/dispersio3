#include "meta/headers.hpp"


/***********************************************************************
     * Database
     * listLanguage

***********************************************************************/
json_t* ach::Database::listLanguage()
{
	json_t     *res = json_object();
	json_t     *lang;
	const char *key;

	json_object_foreach(json_object_get(dm->data, "Translation"), key, lang)
		json_object_set(res, key, json_object_get(lang, "Label"));

	return res;
}



/***********************************************************************
     * Database
     * listTheme

***********************************************************************/
json_t* ach::Database::listTheme()
{
	json_t     *res = json_object();

	list_foreach(theme)
		json_object_set_new(res, theme[i]->name, json_string(theme[i]->name));

	return res;
}
