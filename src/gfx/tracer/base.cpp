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
		case ach::TracerType::ttNone : return new ach::Tracer     (phys);
		case ach::TracerType::ttLine : return new ach::TracerLine (phys);
		case ach::TracerType::ttSmoke: return new ach::TracerSmoke(phys);

		default                      : return new ach::Tracer     (phys);
	}
}
