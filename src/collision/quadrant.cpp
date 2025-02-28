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
void ach::Quadrant::fill(std::vector<ach::PhysLine*> *list, long filter)
{
	list_foreach(lines){
		if (flag_get(filter, lines[i]->type))
			list->push_back(lines[i]);}
}
