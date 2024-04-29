#include "meta/headers.hpp"


/***********************************************************************
     * Database
     * constructor

***********************************************************************/
ach::Database::Database()
{
}



/***********************************************************************
     * Database
     * destructor

***********************************************************************/
ach::Database::~Database()
{
	listDelete(model);
	listDelete(sheet);
}



/***********************************************************************
     * loadContent

***********************************************************************/
template<class T> void loadContent(const char *section, std::vector<T*> *list) {
	json_t     *obj;
	const char *key;

	json_object_foreach(json_object_getv_branch(dm->data, "Data.%s", section), key, obj)
	{
		if (!str_regex_check(key, STR_REGEX_NAME))
		{
			logger->log(ach::llError, "Invalid name: \"Data.%s.%s\"", section, key);
			continue;
		}

		list->push_back(new T(key, obj));
	}
}



/***********************************************************************
     * Database
     * load

***********************************************************************/
void ach::Database::load()
{
	loadContent<ach::DataSheet>("Sheet", &sheet);
	loadContent<ach::DataModel>("Model", &model);
}
