#ifndef __FRAMEWORK_MATH_INTERVAL
#define __FRAMEWORK_MATH_INTERVAL


bool  interval_check(float x, float min , float max);
bool  interval_check(int   x, int   min , int   max);
float interval_set  (float x, float min , float max);
int   interval_set  (int   x, int   min , int   max);
int   interval_loop (int   x, int   min , int   max);
int   interval_side (int   x, int   left, int   right);

#endif
