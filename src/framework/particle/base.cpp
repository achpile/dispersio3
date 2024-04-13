#include "meta/headers.hpp"


/***********************************************************************
     * Particle
     * constructor

***********************************************************************/
ach::Particle::Particle()
{
	age   =  0.0f;
	scale =  1.0f;
}



/***********************************************************************
     * Particle
     * destructor

***********************************************************************/
ach::Particle::~Particle()
{
}



/***********************************************************************
     * Particle
     * update

***********************************************************************/
void ach::Particle::update(float frame)
{
	age += frame;
	vel += acc * frame;
	pos += vel * frame;
}



/***********************************************************************
     * Particle
     * render

***********************************************************************/
void ach::Particle::render(ach::RenderLayer layer)
{
	spr->setPosition(pos);
	spr->setFillColor(clr);
	spr->setScale(scale, scale);

	rm->draw(spr, layer);
}
