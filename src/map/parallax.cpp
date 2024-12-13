#include "meta/headers.hpp"


/***********************************************************************
     * Parallax
     * constructor

***********************************************************************/
ach::Parallax::Parallax(ach::DataParallax *_base)
{
	base = _base;
}



/***********************************************************************
     * Parallax
     * destructor

***********************************************************************/
ach::Parallax::~Parallax()
{
}



/***********************************************************************
     * Parallax
     * render

***********************************************************************/
void ach::Parallax::render(float offset)
{
	list_foreach(base->layers)
		base->layers[i]->render(offset);
}
