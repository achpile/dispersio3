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
void ach::Collision::split(sf::Vector2i _size)
{
	sf::FloatRect area;

	area.width  = COLLISION_QUAD_X;
	area.height = COLLISION_QUAD_Y;

	size.x = ceil((float)_size.x / area.width);
	size.y = ceil((float)_size.y / area.height);
	quad   = new ach::Quadrant**[size.x];

	for (int x = 0; x < size.x; x++)
	{
		quad[x] = new ach::Quadrant*[size.y];

		for (int y = 0; y < size.y; y++)
		{
			quad[x][y] = new ach::Quadrant();

			area.left = area.width  * x;
			area.top  = area.height * y;

			list_foreach(lines)
				if (collision_box_vs_line(area, lines[i]->line, NULL, NULL))
					quad[x][y]->lines.push_back(lines[i]);
		}
	}
}



/***********************************************************************
     * Collision
     * fill

***********************************************************************/
void ach::Collision::fill(std::vector<ach::PhysLine*> *list, sf::FloatRect *rect)
{
	list->clear();

	sf::Vector2i from;
	sf::Vector2i to;

	from.x = floor((rect->left) / COLLISION_QUAD_X);
	from.y = floor((rect->top ) / COLLISION_QUAD_Y);

	to.x = ceil((rect->left + rect->width ) / COLLISION_QUAD_X);
	to.y = ceil((rect->top  + rect->height) / COLLISION_QUAD_Y);

	from.x = std::max(from.x, 0);
	from.y = std::max(from.y, 0);

	to.x = std::min(to.x, size.x);
	to.y = std::min(to.y, size.y);

	for (int x = from.x; x < to.x; x++)
		for (int y = from.y; y < to.y; y++)
			quad[x][y]->fill(list);
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
