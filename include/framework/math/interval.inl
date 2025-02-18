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
     * interval_side

***********************************************************************/
template <typename T>
int interval_side(T x, T left, T right)
{
	if (x < left)
		return SIDE_LEFT;

	if (x > right)
		return SIDE_RIGHT;

	return SIDE_MIDDLE;
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



/***********************************************************************
     * interval_wave

***********************************************************************/
template <typename T>
T interval_wave(T x, T min, T max)
{
	while (!interval_check(x, min, max))
	{
		if (x < min)
			x = min + (min - x);

		if (x > max)
			x = max - (x - max);
	}

	return x;
}

#endif
