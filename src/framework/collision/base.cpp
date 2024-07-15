#include "meta/headers.hpp"


/***********************************************************************
     * Collision
     * constructor

***********************************************************************/
ach::Collision::Collision()
{
}



/***********************************************************************
     * Collision
     * destructor

***********************************************************************/
ach::Collision::~Collision()
{
	list_delete(lines);
}



/***********************************************************************
     * Collision
     * fill

***********************************************************************/
void ach::Collision::fill(std::vector<ach::PhysLine*> *list)
{
	list->clear();

	list_foreach(lines)
		list->push_back(lines[i]);
}



/***********************************************************************
     * Collision
     * sort

***********************************************************************/
void ach::Collision::sort(std::vector<ach::PhysLine*> *list, ach::Phys *phys)
{
	list_foreach(*list)
		(*list)[i]->check(phys);

	sort(list);
}



/***********************************************************************
     * Collision
     * sort

***********************************************************************/
void ach::Collision::sort(std::vector<ach::PhysLine*> *list, ach::Line *line)
{
	list_foreach(*list)
		(*list)[i]->check(line);

	sort(list);
}



/***********************************************************************
     * Collision
     * sort

***********************************************************************/
void ach::Collision::sort(std::vector<ach::PhysLine*> *list)
{
	list->erase(std::remove_if(list->begin(), list->end(), ach::PhysLine::remove), list->end());

	std::sort(list->begin(), list->end(), ach::PhysLine::sort);
}
