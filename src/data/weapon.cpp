#include "meta/headers.hpp"


/***********************************************************************
     * DataWeapon
     * constructor

***********************************************************************/
ach::DataWeapon::DataWeapon(const char *_name, json_t *)
{
	strncpy(name, _name, STR_LEN_NAME);
}



/***********************************************************************
     * DataWeapon
     * destructor

***********************************************************************/
ach::DataWeapon::~DataWeapon()
{
}
