#include "meta/headers.hpp"


/***********************************************************************
     * getContent

***********************************************************************/
template <typename T> T* getContent(const char *name, std::vector<T*> *list)
{
	list_foreach(*list)
		if (!strcmp(name, (*list)[i]->name))
			return (*list)[i];

	logger->log(ach::LogLevel::llError, "Object '%s' is not found", name);

	return NULL;
}



/***********************************************************************
     * Database
     * getFont

***********************************************************************/
ach::DataFont* ach::Database::getFont(const char *name)
{
	return getContent<ach::DataFont>(name, &font);
}



/***********************************************************************
     * Database
     * getTheme

***********************************************************************/
ach::DataTheme* ach::Database::getTheme(const char *name)
{
	return getContent<ach::DataTheme>(name, &theme);
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
     * getCharacter

***********************************************************************/
ach::DataCharacter* ach::Database::getCharacter(const char *name)
{
	return getContent<ach::DataCharacter>(name, &character);
}



/***********************************************************************
     * Database
     * getMap

***********************************************************************/
ach::DataMap* ach::Database::getMap(const char *name)
{
	return getContent<ach::DataMap>(name, &map);
}
