#ifndef __FRAMEWORK_MATH_INTERVAL
#define __FRAMEWORK_MATH_INTERVAL


int   interval_loop (int   x, int   min , int   max);
int   interval_side (int   x, int   left, int   right);

template <typename T> bool interval_check(T x, T min, T max);
template <typename T> T    interval_set  (T x, T min, T max);

#endif
