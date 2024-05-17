#include "meta/headers.hpp"


/***********************************************************************
     * DataProjectile
     * constructor

***********************************************************************/
ach::DataProjectile::DataProjectile(const char *_name, json_t *)
{
	strncpy(name, _name, STR_LEN_NAME);
}



/***********************************************************************
     * DataProjectile
     * destructor

***********************************************************************/
ach::DataProjectile::~DataProjectile()
{
}
