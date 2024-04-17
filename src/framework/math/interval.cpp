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



/***********************************************************************
     * intervalLoop

***********************************************************************/
int intervalLoop(int x, int min, int max)
{
	while (x < min)
		x += (max - min + 1);

	while (x > max)
		x -= (max - min + 1);

	return x;
}
