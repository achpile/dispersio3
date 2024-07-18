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

	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; delete quad[i][j++]);
		delete quad[i];
	}

	delete quad;
}



/***********************************************************************
     * Collision
     * split

***********************************************************************/
void ach::Collision::split(sf::Vector2i _size, sf::Vector2i _area)
{
	area   = _area;
	size.x = ceil((float)_size.x / _area.x);
	size.y = ceil((float)_size.y / _area.y);
	quad   = new ach::Quadrant**[size.x];

	for (int i = 0; i < size.x; i++)
	{
		quad[i] = new ach::Quadrant*[size.y];

		for (int j = 0; j < size.y; j++)
			quad[i][j] = new ach::Quadrant(vector_mult_i(area, sf::Vector2i(i, j)), area);
	}
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
