#include "meta/headers.hpp"


/***********************************************************************
     * Tracer
     * constructor

***********************************************************************/
ach::Tracer::Tracer(ach::Phys *_phys)
{
	phys  = _phys;
	alive = true;
}



/***********************************************************************
     * Tracer
     * destructor

***********************************************************************/
ach::Tracer::~Tracer()
{
}
