#include "meta/headers.hpp"


/***********************************************************************
     * interval_loop

***********************************************************************/
int interval_loop(int x, int min, int max)
{
	while (x < min)
		x += (max - min + 1);

	while (x > max)
		x -= (max - min + 1);

	return x;
}



/***********************************************************************
     * interval_side

***********************************************************************/
int interval_side(int x, int left, int right)
{
	if (x < left)
		return SIDE_LEFT;

	if (x > right)
		return SIDE_RIGHT;

	return SIDE_MIDDLE;
}
