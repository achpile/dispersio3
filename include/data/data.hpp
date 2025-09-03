#ifndef __DATA_DATA
#define __DATA_DATA


namespace ach
{
	struct Database
	{
		std::vector<ach::DataSound*     > sound;
		std::vector<ach::DataFont*      > font;
		std::vector<ach::DataTheme*     > theme;
		std::vector<ach::DataModel*     > model;
		std::vector<ach::DataSheet*     > sheet;
		std::vector<ach::DataProjectile*> projectile;
		std::vector<ach::DataWeapon*    > weapon;
		std::vector<ach::DataItem*      > item;
		std::vector<ach::DataCharacter* > character;
		std::vector<ach::DataCutscene*  > cutscene;
		std::vector<ach::DataMap*       > map;


		 Database();
		~Database();

		void load();

		/*  get.cpp  */
		ach::DataSound      *getSound     (const char *name);
		ach::DataFont       *getFont      (const char *name);
		ach::DataTheme      *getTheme     (const char *name);
		ach::DataModel      *getModel     (const char *name);
		ach::DataSheet      *getSheet     (const char *name);
		ach::DataProjectile *getProjectile(const char *name);
		ach::DataWeapon     *getWeapon    (const char *name);
		ach::DataItem       *getItem      (const char *name);
		ach::DataCharacter  *getCharacter (const char *name);
		ach::DataCutscene   *getCutscene  (const char *name);
		ach::DataMap        *getMap       (const char *name);

		/*  list.cpp  */
		json_t *listLanguage();
		json_t *listTheme();
	};
}

#endif
