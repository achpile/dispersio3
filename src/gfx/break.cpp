#include "meta/headers.hpp"


/***********************************************************************
     * EffectBreak
     * constructor

***********************************************************************/
ach::EffectBreak::EffectBreak(sf::Vector2f pos)
{
	particle = new ach::ParticleSystemSplash(8.0f);

	particle->layer   = ach::RenderLayer::rlGame;
	particle->source  = ach::TimeSource::tsFrame;

	particle->pos     = pos;
	particle->dir     = sf::Vector2f(0.0f, -1.0f);
	particle->life    = 0.25f;
	particle->speed   = 100.0f;
	particle->gravity = true;

	particle->add( 3.0f * MATH_PI / 4.0f);
	particle->add( 1.0f * MATH_PI / 4.0f);
	particle->add(-1.0f * MATH_PI / 4.0f);
	particle->add(-3.0f * MATH_PI / 4.0f);
}



/***********************************************************************
     * EffectBreak
     * destructor

***********************************************************************/
ach::EffectBreak::~EffectBreak()
{
	delete particle;
}



/***********************************************************************
     * EffectBreak
     * update

***********************************************************************/
bool ach::EffectBreak::update()
{
	particle->scale = (particle->life - particle->age) / particle->life;

	return particle->update();
}



/***********************************************************************
     * EffectBreak
     * render

***********************************************************************/
void ach::EffectBreak::render()
{
	particle->render();
}
