#include "meta/headers.hpp"


/***********************************************************************
     * TracerSmoke
     * constructor

***********************************************************************/
ach::TracerSmoke::TracerSmoke(ach::Phys *_phys) : Tracer(_phys)
{
	smoke = new ach::ParticleSystemSmoke();

	smoke->real   = false;
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
bool ach::TracerSmoke::update()
{
	if (alive)
		correct();

	smoke->alive = alive;

	return smoke->update();
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



/***********************************************************************
     * TracerSmoke
     * correct

***********************************************************************/
void ach::TracerSmoke::correct()
{
	smoke->pos = phys->pos;
}
