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
	list_delete(sheet);
	list_delete(model);
	list_delete(projectile);
	list_delete(weapon);
	list_delete(body);
	list_delete(character);
}



/***********************************************************************
     * loadContent

***********************************************************************/
template<class T> void loadContent(const char *section, std::vector<T*> *list)
{
	json_t     *obj;
	const char *key;

	json_object_foreach(json_object_getv_branch(dm->data, "Data.%s", section), key, obj)
	{
		list->push_back(new T(obj));
		strncpy(list->back()->name, key, STR_LEN_NAME);
	}
}



/***********************************************************************
     * Database
     * load

***********************************************************************/
void ach::Database::load()
{
	loadContent<ach::DataSheet     >("Sheet"     , &sheet     );
	loadContent<ach::DataModel     >("Model"     , &model     );
	loadContent<ach::DataProjectile>("Projectile", &projectile);
	loadContent<ach::DataWeapon    >("Weapon"    , &weapon    );
	loadContent<ach::DataBody      >("Body"      , &body      );
	loadContent<ach::DataCharacter >("Character" , &character );
}
