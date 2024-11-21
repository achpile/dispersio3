#ifndef __FRAMEWORK_MATH_BASE
#define __FRAMEWORK_MATH_BASE


bool  math_epsilon(float x);
float math_fade(float x, float slope, float length);
float math_decay(float x, float start, float end);
float math_linear(float x, float k, float m);
float math_sqr(float x);

#endif
