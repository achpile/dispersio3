#ifndef __DATA_WEAPON
#define __DATA_WEAPON


namespace ach
{
	struct DataWeapon
	{
		char    name[STR_LEN_NAME];


		 DataWeapon(const char *_name, json_t *obj);
		~DataWeapon();
	};
}

#endif
