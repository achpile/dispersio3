#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemSmoke
     * constructor

***********************************************************************/
ach::ParticleSystemSmoke::ParticleSystemSmoke() : ParticleSystem(2.0f)
{
	age   = 0.0f;
	freq  = 0.07f;
	life  = 0.35f;
	alive = true;
	pos   = sf::Vector2f(0.0f, 0.0f);
	color = sf::Color::White;
}



/***********************************************************************
     * ParticleSystemSmoke
     * destructor

***********************************************************************/
ach::ParticleSystemSmoke::~ParticleSystemSmoke()
{
}



/***********************************************************************
     * ParticleSystemSmoke
     * update

***********************************************************************/
bool ach::ParticleSystemSmoke::update()
{
	age += tm->get(source);

	while (alive && age > freq)
	{
		age -= freq;
		add();
	}

	return alive || particles.size();
}



/***********************************************************************
     * ParticleSystemSmoke
     * process

***********************************************************************/
bool ach::ParticleSystemSmoke::process(ach::Particle *particle)
{
	particle->scale    = particle->age * (1.3f / life) + 1.0f;
	particle->offset.x = (particle->age + 2.0f) * sin(particle->age * 20.0f);
	particle->color.a  = math_linear(particle->age, -(250.0f / life), color.a);

	return particle->age <= life;
}



/***********************************************************************
     * ParticleSystemSmoke
     * add

***********************************************************************/
void ach::ParticleSystemSmoke::add()
{
	particles.push_back(new ach::Particle());

	particles.back()->pos   = pos;
	particles.back()->vel   = sf::Vector2f(0.0f, -20.0f);
	particles.back()->spr   = spr;
	particles.back()->color = color;

	particles.back()->calc();
}
