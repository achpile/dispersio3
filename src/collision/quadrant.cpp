#include "meta/headers.hpp"


/***********************************************************************
     * Quadrant
     * constructor

***********************************************************************/
ach::Quadrant::Quadrant()
{
}



/***********************************************************************
     * Quadrant
     * destructor

***********************************************************************/
ach::Quadrant::~Quadrant()
{
	lines.clear();
}



/***********************************************************************
     * Quadrant
     * fill

***********************************************************************/
void ach::Quadrant::fill(std::vector<ach::PhysLine*> *list)
{
	list_foreach(lines)
		list->push_back(lines[i]);
}
