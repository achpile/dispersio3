#include "meta/headers.hpp"


/***********************************************************************
     * DataContent
     * setName

***********************************************************************/
void ach::DataContent::setName(const char *_name)
{
	strncpy(name, _name, STR_LEN_NAME);
}
