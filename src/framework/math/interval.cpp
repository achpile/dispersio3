#include "meta/headers.hpp"


/***********************************************************************
     * interval_check

***********************************************************************/
bool interval_check(int x, int min, int max)
{
	return (x >= min) && (x <= max);
}



/***********************************************************************
     * interval_set

***********************************************************************/
int interval_set(int x, int min, int max)
{
	if (x < min)
		return min;

	if (x > max)
		return max;

	return x;
}



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
