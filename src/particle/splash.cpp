#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemSplash
     * constructor

***********************************************************************/
ach::ParticleSystemSplash::ParticleSystemSplash(float size) : ParticleSystem(size)
{
	age     = 0.0f;
	life    = 1.0f;
	scale   = 1.0f;
	cone    = 0.0f;
	speed   = 0.0f;
	pos     = sf::Vector2f(0.0f, 0.0f);
	color   = sf::Color::White;
	gravity = false;
	rotate  = false;
}



/***********************************************************************
     * ParticleSystemSplash
     * destructor

***********************************************************************/
ach::ParticleSystemSplash::~ParticleSystemSplash()
{
}



/***********************************************************************
     * ParticleSystemSplash
     * update

***********************************************************************/
bool ach::ParticleSystemSplash::update()
{
	age += tm->get(realtime);

	return age < life;
}



/***********************************************************************
     * ParticleSystemSplash
     * process

***********************************************************************/
bool ach::ParticleSystemSplash::process(ach::Particle *particle)
{
	particle->color = color;
	particle->scale = scale;

	return true;
}



/***********************************************************************
     * ParticleSystemSplash
     * add

***********************************************************************/
void ach::ParticleSystemSplash::add(float angle)
{
	particles.push_back(new ach::Particle());

	particles.back()->pos    = pos;
	particles.back()->vel    = vector_set_len(vector_create(angle), speed);
	particles.back()->spr    = spr;
	particles.back()->color  = color;
	particles.back()->rotate = rotate;

	particles.back()->calc();

	if (gravity)
		particles.back()->acc = sf::Vector2f(0.0f, 500.0f);
}



/***********************************************************************
     * ParticleSystemSplash
     * init

***********************************************************************/
void ach::ParticleSystemSplash::init(int count)
{
	float angle = vector_angle(dir);
	float step  = 2 * cone / (count - 1);

	for (int i = 0; i < count; i++)
		add(angle + step * i - cone);
}
