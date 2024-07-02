#include "meta/headers.hpp"


/***********************************************************************
     * Background
     * constructor

***********************************************************************/
ach::Background::Background()
{
	stars = new ach::ParticleSystemStars(RENDER_LAYER_BG_X, RENDER_LAYER_BG_Y, 70);

	stars->source = ach::TimeSource::tsReal;
	stars->layer  = ach::RenderLayer::rlBG;
}



/***********************************************************************
     * Background
     * destructor

***********************************************************************/
ach::Background::~Background()
{
	delete stars;
}
