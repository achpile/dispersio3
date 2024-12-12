#include "meta/headers.hpp"


/***********************************************************************
     * Background
     * constructor

***********************************************************************/
ach::Background::Background(const char *filename, float _factor)
{
	factor = _factor;
	spr    = new ach::Sprite(filename, true, false);
}



/***********************************************************************
     * Background
     * destructor

***********************************************************************/
ach::Background::~Background()
{
	delete spr;
}
