#ifndef __DATA_PROJECTILE
#define __DATA_PROJECTILE


namespace ach
{
	struct DataProjectile
	{
		char    name[STR_LEN_NAME];


		 DataProjectile(const char *_name, json_t *obj);
		~DataProjectile();
	};
}

#endif
