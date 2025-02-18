#ifndef __FRAMEWORK_MATH_INTERVAL
#define __FRAMEWORK_MATH_INTERVAL


int interval_loop (int x, int min, int max);

template <typename T> int  interval_side (T x, T left, T right);
template <typename T> bool interval_check(T x, T min , T max  );
template <typename T> T    interval_set  (T x, T min , T max  );
template <typename T> T    interval_wave (T x, T min , T max  );

#endif
