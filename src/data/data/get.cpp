#include "meta/headers.hpp"


/***********************************************************************
     * getContent

***********************************************************************/
template <typename T> T* getContent(const char *name, std::vector<T*> *list)
{
	if (!name)
	{
		logger->log(ach::LogLevel::llError, "Attempt to get NULL object", name);
		return NULL;
	}


	list_foreach(*list)
		if (!strcmp(name, (*list)[i]->name))
			return (*list)[i];

	logger->log(ach::LogLevel::llError, "Object '%s' is not found", name);

	return NULL;
}



/***********************************************************************
     * Database
     * getSound

***********************************************************************/
ach::DataSound* ach::Database::getSound(const char *name)
{
	return getContent<ach::DataSound>(name, &sound);
}



/***********************************************************************
     * Database
     * getTrack

***********************************************************************/
ach::DataTrack* ach::Database::getTrack(const char *name)
{
	return getContent<ach::DataTrack>(name, &track);
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
     * getSprite

***********************************************************************/
ach::DataSprite* ach::Database::getSprite(const char *name)
{
	return getContent<ach::DataSprite>(name, &sprite);
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
     * getItem

***********************************************************************/
ach::DataItem* ach::Database::getItem(const char *name)
{
	return getContent<ach::DataItem>(name, &item);
}



/***********************************************************************
     * Database
     * getNPC

***********************************************************************/
ach::DataNPC* ach::Database::getNPC(const char *name)
{
	return getContent<ach::DataNPC>(name, &npc);
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
     * getBoss

***********************************************************************/
ach::DataBoss* ach::Database::getBoss(const char *name)
{
	return getContent<ach::DataBoss>(name, &boss);
}



/***********************************************************************
     * Database
     * getCutscene

***********************************************************************/
ach::DataCutscene* ach::Database::getCutscene(const char *name)
{
	return getContent<ach::DataCutscene>(name, &cutscene);
}



/***********************************************************************
     * Database
     * getMap

***********************************************************************/
ach::DataMap* ach::Database::getMap(const char *name)
{
	return getContent<ach::DataMap>(name, &map);
}
