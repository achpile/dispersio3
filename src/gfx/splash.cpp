#include "meta/headers.hpp"


/***********************************************************************
     * EffectSplash
     * constructor

***********************************************************************/
ach::EffectSplash::EffectSplash(sf::Vector2f pos, sf::Color color, float cone, int count) : Effect()
{
	particle = new ach::ParticleSystemSplash(PARTICLE_SPLASH_SIZE);

	particle->layer   = ach::RenderLayer::rlGame;
	particle->source  = ach::TimeSource::tsFrame;

	particle->pos     = pos;
	particle->dir     = sf::Vector2f(0.0f, -1.0f);
	particle->color   = color;
	particle->cone    = cone;
	particle->life    = 0.06f;
	particle->speed   = 300.0f;
	particle->gravity = false;

	particle->init(count);
}



/***********************************************************************
     * EffectSplash
     * destructor

***********************************************************************/
ach::EffectSplash::~EffectSplash()
{
	delete particle;
}



/***********************************************************************
     * EffectSplash
     * update

***********************************************************************/
bool ach::EffectSplash::update()
{
	return particle->update();
}



/***********************************************************************
     * EffectSplash
     * render

***********************************************************************/
void ach::EffectSplash::render()
{
	particle->render();
}
