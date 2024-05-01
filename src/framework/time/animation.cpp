#include "meta/headers.hpp"


/***********************************************************************
     * Animation
     * constructor

***********************************************************************/
ach::Animation::Animation()
{
	frame  = 0;
	start  = 0;
	end    = 0;
}



/***********************************************************************
     * Animation
     * destructor

***********************************************************************/
ach::Animation::~Animation()
{
}



/***********************************************************************
     * Animation
     * update

***********************************************************************/
void ach::Animation::update()
{
	if (start == end)
		return;

	frame += framer.update();

	if (loop)
		frame = interval_loop(frame, start, end);
	else
		frame = interval_set(frame, start, end);
}



/***********************************************************************
     * Animation
     * reset

***********************************************************************/
void ach::Animation::reset()
{
	frame = start;

	framer.reset();
}



/***********************************************************************
     * Animation
     * set

***********************************************************************/
void ach::Animation::set(int _start, int _end, bool _loop, float rate, int frames)
{
	if (start == _start &&
	    end   == _end   &&
	    loop  == _loop  &&
	    rate  == framer.timer)
		return;

	start = _start;
	end   = _end;
	loop  = _loop;
	frame = start;

	if (end == -1 || end >= frames)
		end = frames - 1;

	framer.set(rate);
}



/***********************************************************************
     * Animation
     * set

***********************************************************************/
void ach::Animation::set(json_t *obj, int frames)
{
	set(json_object_get_integer(obj, "Start"),
	    json_object_get_integer(obj, "End"  ),
	    json_object_get_boolean(obj, "Loop" ),
	    json_object_get_real   (obj, "Rate" ),
	    frames);
}
