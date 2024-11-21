#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemStars
     * constructor

***********************************************************************/
ach::ParticleSystemStars::ParticleSystemStars(int _width, int _height, int count) : ParticleSystem(2.0f)
{
	age    = 0.0f;
	freq   = 0.05f;

	width  = _width;
	height = _height;

	for (int i = 0; i < count; i++)
		add(rand() % width);
}



/***********************************************************************
     * ParticleSystemStars
     * destructor

***********************************************************************/
ach::ParticleSystemStars::~ParticleSystemStars()
{
}



/***********************************************************************
     * ParticleSystemStars
     * update

***********************************************************************/
bool ach::ParticleSystemStars::update()
{
	age += tm->get(source);

	while (age > freq)
	{
		age -= freq;
		add(width);
	}

	return true;
}



/***********************************************************************
     * ParticleSystemStars
     * process

***********************************************************************/
bool ach::ParticleSystemStars::process(ach::Particle *particle)
{
	return particle->pos.x >= 0.0f;
}



/***********************************************************************
     * ParticleSystemStars
     * add

***********************************************************************/
void ach::ParticleSystemStars::add(float x)
{
	unsigned char rnd = rand() % 7;
	unsigned char clr = 63 + rnd * 32;

	particles.push_back(new ach::Particle());

	particles.back()->pos   = sf::Vector2f(x, rand() % height);
	particles.back()->vel   = sf::Vector2f(-120.0f - rnd * 20.0f, 0.0f);
	particles.back()->spr   = spr;
	particles.back()->color = sf::Color(clr, clr, clr);

	particles.back()->calc();
}
