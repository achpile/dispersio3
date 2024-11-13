#ifndef __FRAMEWORK_MATH_INTERVAL_INL
#define __FRAMEWORK_MATH_INTERVAL_INL


/***********************************************************************
     * interval_check

***********************************************************************/
template <typename T>
bool interval_check(T x, T min, T max)
{
	return ((x >= min) && (x <= max)) || ((x <= min) && (x >= max));
}



/***********************************************************************
     * interval_set

***********************************************************************/
template <typename T>
T interval_set(T x, T min, T max)
{
	if (x < min)
		return min;

	if (x > max)
		return max;

	return x;
}

#endif
