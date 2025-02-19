#ifndef __FRAMEWORK_MATH_MATH
#define __FRAMEWORK_MATH_MATH


int   math_sign(float x);
bool  math_epsilon(float x);
float math_fade(float x, float slope, float length);
float math_decay(float x, float start, float end);
float math_linear(float x, float k, float m);
float math_sqr(float x);

#endif
