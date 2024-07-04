#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * collide

***********************************************************************/
void ach::Map::collide()
{
	list_foreach(characters)
		collision->collide(&characters[i]->phys);

	// collide bullets <-> characters

	// collide bullets <-> physlines
}
