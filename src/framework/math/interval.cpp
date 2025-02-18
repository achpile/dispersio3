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
