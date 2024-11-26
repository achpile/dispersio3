#ifndef __DATA_DATA
#define __DATA_DATA


namespace ach
{
	struct Database
	{
		std::vector<ach::DataFont*      > font;
		std::vector<ach::DataTheme*     > theme;
		std::vector<ach::DataModel*     > model;
		std::vector<ach::DataSheet*     > sheet;
		std::vector<ach::DataProjectile*> projectile;
		std::vector<ach::DataWeapon*    > weapon;
		std::vector<ach::DataBody*      > body;
		std::vector<ach::DataCharacter* > character;


		 Database();
		~Database();

		void load();

		/*  get.cpp  */
		ach::DataFont       *getFont      (const char *name);
		ach::DataTheme      *getTheme     (const char *name);
		ach::DataModel      *getModel     (const char *name);
		ach::DataSheet      *getSheet     (const char *name);
		ach::DataProjectile *getProjectile(const char *name);
		ach::DataWeapon     *getWeapon    (const char *name);
		ach::DataBody       *getBody      (const char *name);
		ach::DataCharacter  *getCharacter (const char *name);

		/*  list.cpp  */
		json_t *listLanguage();
		json_t *listTheme();
	};
}

#endif
