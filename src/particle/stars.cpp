#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemStars
     * constructor

***********************************************************************/
ach::ParticleSystemStars::ParticleSystemStars() : ParticleSystem(2.0f)
{
	age  = 0.0f;
	freq = 0.05f;

	for (int i = 0; i < 70; i++)
		add(rand() % RENDER_LAYER_BG_X);
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
	age += tm->real;

	while (age > freq)
	{
		age -= freq;
		add(RENDER_LAYER_BG_X);
	}

	render(ach::RenderLayer::rlBG, tm->real);

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

	particles.back()->pos   = sf::Vector2f(x, rand() % RENDER_LAYER_BG_Y);
	particles.back()->vel   = sf::Vector2f(-120.0f - rnd * 20.0f, 0.0f);
	particles.back()->spr   = spr;
	particles.back()->color = sf::Color(clr, clr, clr);
}
