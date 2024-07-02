#include "meta/headers.hpp"


/***********************************************************************
     * Background
     * constructor

***********************************************************************/
ach::Background::Background()
{
	stars = new ach::ParticleSystemStars();
}



/***********************************************************************
     * Background
     * destructor

***********************************************************************/
ach::Background::~Background()
{
	delete stars;
}
