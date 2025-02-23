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
	particle->cone    = MATH_PI;
	particle->life    = 0.25f;
	particle->speed   = 75.0f;
	particle->gravity = true;

	particle->init(4);
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
