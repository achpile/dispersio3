#include "meta/headers.hpp"


/***********************************************************************
     * MenuItem
     * constructor

***********************************************************************/
ach::MenuItem::MenuItem(std::string _caption)
{
	caption = _caption;
}



/***********************************************************************
     * MenuItem
     * destructor

***********************************************************************/
ach::MenuItem::~MenuItem()
{
	listDelete(items);
}
