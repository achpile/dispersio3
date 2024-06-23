#ifndef __DATA_BASE
#define __DATA_BASE


namespace ach
{
	struct Database
	{
		std::vector<ach::DataModel*     > model;
		std::vector<ach::DataSheet*     > sheet;
		std::vector<ach::DataProjectile*> projectile;
		std::vector<ach::DataWeapon*    > weapon;
		std::vector<ach::DataBody*      > body;
		std::vector<ach::DataCharacter* > character;


		 Database();
		~Database();

		void load();

		ach::DataModel      *getModel     (const char *name);
		ach::DataSheet      *getSheet     (const char *name);
		ach::DataProjectile *getProjectile(const char *name);
		ach::DataWeapon     *getWeapon    (const char *name);
		ach::DataBody       *getBody      (const char *name);
		ach::DataCharacter  *getCharacter (const char *name);
	};
}

#endif
