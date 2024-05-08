#include "meta/headers.hpp"


/***********************************************************************
     * interval_check

***********************************************************************/
template<typename T> bool interval_check(T x, T min, T max)
{
	return ((x >= min) && (x <= max)) || ((x <= min) && (x >= max));
}



/***********************************************************************
     * interval_check

***********************************************************************/
bool interval_check(int x, int min, int max)
{
	return interval_check<int>(x, min, max);
}



/***********************************************************************
     * interval_check

***********************************************************************/
bool interval_check(float x, float min, float max)
{
	return interval_check<float>(x, min, max);
}



/***********************************************************************
     * interval_set

***********************************************************************/
template<typename T> T interval_set(T x, T min, T max)
{
	if (x < min)
		return min;

	if (x > max)
		return max;

	return x;
}



/***********************************************************************
     * interval_set

***********************************************************************/
int interval_set(int x, int min, int max)
{
	return interval_set<int>(x, min, max);
}



/***********************************************************************
     * interval_set

***********************************************************************/
float interval_set(float x, float min, float max)
{
	return interval_set<float>(x, min, max);
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
