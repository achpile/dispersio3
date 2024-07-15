#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemSplash
     * constructor

***********************************************************************/
ach::ParticleSystemSplash::ParticleSystemSplash() : ParticleSystem(1.0f)
{
	age     = 0.0f;
	life    = 1.0f;
	cone    = 0.0f;
	speed   = 0.0f;
	pos     = sf::Vector2f(0.0f, 0.0f);
	color   = sf::Color::White;
	gravity = false;
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
	age += tm->get(source);

	return age < life;
}



/***********************************************************************
     * ParticleSystemSplash
     * process

***********************************************************************/
bool ach::ParticleSystemSplash::process(ach::Particle *particle)
{
	particle->color = color;

	return true;
}



/***********************************************************************
     * ParticleSystemSplash
     * add

***********************************************************************/
void ach::ParticleSystemSplash::add()
{
	float angle = vector_angle(dir);

	particles.push_back(new ach::Particle());

	particles.back()->pos   = pos;
	particles.back()->vel   = vector_set_len(vector_create(angle + random_float(cone)), random_float(speed / 2.0f, speed));
	particles.back()->spr   = spr;
	particles.back()->color = color;

	if (gravity)
		particles.back()->acc = sf::Vector2f(0.0f, PHYS_GRAVITY / 2.0f);
}



/***********************************************************************
     * ParticleSystemSplash
     * init

***********************************************************************/
void ach::ParticleSystemSplash::init(int count)
{
	for (int i = 0; i < count; i++)
		add();
}
