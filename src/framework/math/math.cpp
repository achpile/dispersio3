#include "meta/headers.hpp"


/***********************************************************************
     * math_sign

***********************************************************************/
int math_sign(float x)
{
	if (x < 0.0f) return -1;
	if (x > 0.0f) return  1;

	return 0;
}



/***********************************************************************
     * math_epsilon

***********************************************************************/
bool math_epsilon(float x)
{
	return fabs(x) < MATH_EPSILON;
}



/***********************************************************************
     * math_fade

***********************************************************************/
float math_fade(float x, float slope, float length)
{
	if (x < 0.0f)
		return 0.0f;

	if (x < slope)
		return x / slope;

	if (x < slope + length)
		return 1.0f;

	if (x < slope * 2 + length)
		return 1.0f - (x - (length + slope)) / slope;

	return 0.0f;
}



/***********************************************************************
     * math_decay

***********************************************************************/
float math_decay(float x, float start, float end)
{
	if (x < start)
		return 1.0f;

	if (x > end)
		return 0.0f;

	return (end - x) / (end - start);
}



/***********************************************************************
     * math_linear

***********************************************************************/
float math_linear(float x, float k, float m)
{
	return k * x + m;
}



/***********************************************************************
     * math_sqr

***********************************************************************/
float math_sqr(float x)
{
	return x * x;
}
