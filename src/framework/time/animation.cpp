#include "meta/headers.hpp"


/***********************************************************************
     * Animation
     * constructor

***********************************************************************/
ach::Animation::Animation()
{
	frames = 0;
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
     * init

***********************************************************************/
void ach::Animation::init(int _frames, float _rate)
{
	drate  = _rate;
	frames = _frames;

	set(0, -1, true, drate);
}



/***********************************************************************
     * Animation
     * set

***********************************************************************/
void ach::Animation::set(int _start, int _end, bool _loop, float _rate)
{
	float rate = (_rate != 0.0f) ? _rate : drate;

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
}
