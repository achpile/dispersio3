#include "meta/headers.hpp"


/***********************************************************************
     * intervalCheck

***********************************************************************/
bool intervalCheck(int x, int min, int max)
{
	return (x >= min) && (x <= max);
}



/***********************************************************************
     * intervalSet

***********************************************************************/
int intervalSet(int x, int min, int max)
{
	if (x < min)
		return min;

	if (x > max)
		return max;

	return x;
}
