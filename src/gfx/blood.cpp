#include "meta/headers.hpp"


/***********************************************************************
     * EffectBlood
     * constructor

***********************************************************************/
ach::EffectBlood::EffectBlood(ach::ProcessWorld *_world, sf::Vector2f pos, sf::Vector2f vel, sf::Color _color)
{
	world    = _world;
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
	if (!particle->update())
		return false;

	list_foreach(particle->particles)
		if (particle->particles[i]->moving)
			if (world->map->collideLine(&particle->particles[i]->line))
				particle->particles[i]->moving = false;

	particle->color.a = color.a * math_decay(particle->age, PARTICLE_BLOOD_CLEAR, PARTICLE_BLOOD_LIFE);

	return true;
}



/***********************************************************************
     * EffectBlood
     * render

***********************************************************************/
void ach::EffectBlood::render()
{
	particle->render();
}
