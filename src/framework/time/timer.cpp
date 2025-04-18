#include "meta/headers.hpp"


/***********************************************************************
     * Timer
     * constructor

***********************************************************************/
ach::Timer::Timer()
{
	set(0.0f);
}



/***********************************************************************
     * Timer
     * destructor

***********************************************************************/
ach::Timer::~Timer()
{
}



/***********************************************************************
     * Timer
     * set

***********************************************************************/
void ach::Timer::set(float _timer)
{
	timer = _timer;
	value = _timer;
}



/***********************************************************************
     * Timer
     * reset

***********************************************************************/
void ach::Timer::reset()
{
	value = timer;
}



/***********************************************************************
     * Timer
     * zero

***********************************************************************/
void ach::Timer::zero()
{
	value = 0.0f;
}



/***********************************************************************
     * Timer
     * progress

***********************************************************************/
float ach::Timer::progress(bool invert)
{
	if (!timer)
		return 0.0f;

	return interval_set(invert ? value / timer : (timer - value) / timer, 0.0f, 1.0f);
}



/***********************************************************************
     * Timer
     * update

***********************************************************************/
bool ach::Timer::update(bool real)
{
	if (value <= 0)
		return false;

	value -= tm->get(real);

	if (value <= 0)
	{
		value = 0;
	}

	return value > 0.0f;
}



/***********************************************************************
     * Timer
     * isActive

***********************************************************************/
bool ach::Timer::isActive()
{
	return value > 0.0f;
}
