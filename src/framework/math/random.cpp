#include "meta/headers.hpp"


/***********************************************************************
     * random_float

***********************************************************************/
float random_float(float min, float max)
{
	return min + (max - min) * (float)(rand() % 100) / 99.0f;
}



/***********************************************************************
     * random_int

***********************************************************************/
int random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}



/***********************************************************************
     * random_sign

***********************************************************************/
int random_sign()
{
	return (rand() % 2) ? -1 : 1;
}
