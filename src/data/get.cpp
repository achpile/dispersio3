#include "meta/headers.hpp"


/***********************************************************************
     * getContent

***********************************************************************/
template<class T> T* getContent(const char *name, std::vector<T*> *list)
{
	listForeach(*list)
		if (!strcmp(name, (*list)[i]->name))
			return (*list)[i];

	logger->log(ach::LogLevel::llError, "Object \"%s\" is not found", name);

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



/***********************************************************************
     * Database
     * getBody

***********************************************************************/
ach::DataBody* ach::Database::getBody(const char *name)
{
	return getContent<ach::DataBody>(name, &body);
}



/***********************************************************************
     * Database
     * getCharacter

***********************************************************************/
ach::DataCharacter* ach::Database::getCharacter(const char *name)
{
	return getContent<ach::DataCharacter>(name, &character);
}
