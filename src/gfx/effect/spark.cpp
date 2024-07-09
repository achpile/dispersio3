#include "meta/headers.hpp"


/***********************************************************************
     * EffectSpark
     * constructor

***********************************************************************/
ach::EffectSpark::EffectSpark(sf::Vector2f pos, sf::Vector2f dir, sf::Color color) : Effect(pos, dir, color)
{
	particle = new ach::ParticleSystemSplash();

	particle->layer   = ach::RenderLayer::rlGame;
	particle->source  = ach::TimeSource::tsFrame;

	particle->pos     = pos;
	particle->dir     = dir;
	particle->color   = color;
	particle->cone    = MATH_PI / 12.0f;
	particle->life    = 0.3f;
	particle->speed   = 200.0f;
	particle->gravity = true;

	particle->init(5);
}



/***********************************************************************
     * EffectSpark
     * destructor

***********************************************************************/
ach::EffectSpark::~EffectSpark()
{
	delete particle;
}



/***********************************************************************
     * EffectSpark
     * update

***********************************************************************/
bool ach::EffectSpark::update()
{
	return particle->update();
}



/***********************************************************************
     * EffectSpark
     * render

***********************************************************************/
void ach::EffectSpark::render()
{
	particle->render();
}
