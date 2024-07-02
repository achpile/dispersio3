#include "meta/headers.hpp"


/***********************************************************************
     * TracerSmoke
     * constructor

***********************************************************************/
ach::TracerSmoke::TracerSmoke(ach::Phys *_phys) : Tracer(_phys)
{
	smoke = new ach::ParticleSystemSmoke();

	smoke->source = ach::TimeSource::tsFrame;
	smoke->layer  = ach::RenderLayer::rlGame;
}



/***********************************************************************
     * TracerSmoke
     * destructor

***********************************************************************/
ach::TracerSmoke::~TracerSmoke()
{
	delete smoke;
}



/***********************************************************************
     * TracerSmoke
     * update

***********************************************************************/
void ach::TracerSmoke::update()
{
	smoke->pos = phys->pos;

	smoke->update();
}



/***********************************************************************
     * TracerSmoke
     * render

***********************************************************************/
void ach::TracerSmoke::render()
{
	smoke->render();
}



/***********************************************************************
     * TracerSmoke
     * init

***********************************************************************/
void ach::TracerSmoke::init()
{
	smoke->pos   = phys->pos;
	smoke->color = color;

	smoke->add();
}
