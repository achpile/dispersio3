#include "meta/headers.hpp"


/***********************************************************************
     * EffectBlood
     * constructor

***********************************************************************/
ach::EffectBlood::EffectBlood(sf::Vector2f pos, sf::Vector2f vel, sf::Color _color)
{
	color    = _color;
	particle = new ach::ParticleSystemSplash(PARTICLE_BLOOD_SIZE);

	particle->layer   = ach::RenderLayer::rlGame;
	particle->source  = ach::TimeSource::tsFrame;

	particle->pos     = pos;
	particle->dir     = vector_norm(vel);
	particle->color   = color;
	particle->cone    = MATH_PI / 4.0f;
	particle->life    = PARTICLE_BLOOD_LIFE;
	particle->speed   = PARTICLE_BLOOD_SPEED;
	particle->gravity = true;

	particle->init(10);
}



/***********************************************************************
     * EffectBlood
     * destructor

***********************************************************************/
ach::EffectBlood::~EffectBlood()
{
	delete particle;
}



/***********************************************************************
     * EffectBlood
     * update

***********************************************************************/
bool ach::EffectBlood::update()
{
	return particle->update();
}



/***********************************************************************
     * EffectBlood
     * render

***********************************************************************/
void ach::EffectBlood::render()
{
	particle->render();
}
