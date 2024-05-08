#include "meta/headers.hpp"


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
     * math_linear

***********************************************************************/
float math_linear(float x, float k, float m)
{
	return k * x + m;
}
