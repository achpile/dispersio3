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
     * getModel

***********************************************************************/
ach::DataModel* ach::Database::getModel(const char *name)
{
	return getContent<ach::DataModel>(name, &model);
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
     * getProjectile

***********************************************************************/
ach::DataProjectile* ach::Database::getProjectile(const char *name)
{
	return getContent<ach::DataProjectile>(name, &projectile);
}



/***********************************************************************
     * Database
     * getWeapon

***********************************************************************/
ach::DataWeapon* ach::Database::getWeapon(const char *name)
{
	return getContent<ach::DataWeapon>(name, &weapon);
}
