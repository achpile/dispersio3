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
	list_delete(sound);
	list_delete(font);
	list_delete(theme);
	list_delete(sheet);
	list_delete(model);
	list_delete(projectile);
	list_delete(weapon);
	list_delete(item);
	list_delete(character);
	list_delete(cutscene);
	list_delete(map);
}



/***********************************************************************
     * loadContent

***********************************************************************/
template <typename T> void loadContent(const char *section, std::vector<T*> *list)
{
	json_t     *obj;
	const char *key;

	json_object_foreach(json_object_getv_branch(dm->data, "Data.%s", section), key, obj)
	{
		list->push_back(new T(obj));
		list->back()->setName(key);
	}
}



/***********************************************************************
     * Database
     * load

***********************************************************************/
void ach::Database::load()
{
	loadContent<ach::DataSound     >("SFX"            , &sound     );

	loadContent<ach::DataFont      >("UI.Font"        , &font      );
	loadContent<ach::DataTheme     >("UI.Theme"       , &theme     );

	loadContent<ach::DataSheet     >("GFX.Sheet"      , &sheet     );
	loadContent<ach::DataModel     >("GFX.Model"      , &model     );

	loadContent<ach::DataProjectile>("Game.Projectile", &projectile);
	loadContent<ach::DataWeapon    >("Game.Weapon"    , &weapon    );
	loadContent<ach::DataItem      >("Game.Item"      , &item      );
	loadContent<ach::DataCharacter >("Game.Character" , &character );
	loadContent<ach::DataCutscene  >("Game.Cutscene"  , &cutscene  );
	loadContent<ach::DataMap       >("Game.Map"       , &map       );
}
