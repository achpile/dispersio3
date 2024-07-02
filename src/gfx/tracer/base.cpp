#include "meta/headers.hpp"


/***********************************************************************
     * Tracer
     * constructor

***********************************************************************/
ach::Tracer::Tracer(ach::Phys *_phys)
{
	phys = _phys;
}



/***********************************************************************
     * Tracer
     * destructor

***********************************************************************/
ach::Tracer::~Tracer()
{
}



/***********************************************************************
     * Tracer
     * create

***********************************************************************/
ach::Tracer* ach::Tracer::create(ach::TracerType type, ach::Phys *phys)
{
	switch (type)
	{
		case ach::TracerType::ttNone: return new ach::Tracer(phys);

		default                     : return new ach::Tracer(phys);
	}
}
