#include "meta/headers.hpp"


/***********************************************************************
     * getContent

***********************************************************************/
template<class T> T* getContent(const char *name, std::vector<T*> *list) {
	for (unsigned int i = 0; i < list->size(); i++)
		if (!strcmp(name, (*list)[i]->name))
			return (*list)[i];

	return NULL;
}



/***********************************************************************
     * Database
     * getSheet

***********************************************************************/
ach::DataSheet* ach::Database::getSheet(const char *name)
{
	return getContent<ach::DataSheet>(name, &sheet);
}



/***********************************************************************
     * Database
     * getModel

***********************************************************************/
ach::DataModel* ach::Database::getModel(const char *name)
{
	return getContent<ach::DataModel>(name, &model);
}
