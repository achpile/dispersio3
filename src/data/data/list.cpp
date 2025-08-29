#include "meta/headers.hpp"


/***********************************************************************
     * Database
     * listLanguage

***********************************************************************/
json_t* ach::Database::listLanguage()
{
	json_t     *res = json_array();
	json_t     *lang;
	const char *key;

	json_object_foreach(json_object_get(dm->data, "Translation"), key, lang)
		json_array_append_new(res, json_pack("{s:s, s:s, s:b}", "Name", json_object_get_string(lang, "Label"), "Value", key, "Token", false));

	return res;
}



/***********************************************************************
     * Database
     * listTheme

***********************************************************************/
json_t* ach::Database::listTheme()
{
	json_t *res = json_array();

	list_foreach(theme)
		json_array_append_new(res, json_pack("{s:s, s:s, s:b}", "Name", theme[i]->name, "Value", theme[i]->name, "Token", false));

	return res;
}
