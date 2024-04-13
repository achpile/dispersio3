#include "meta/headers.hpp"


/***********************************************************************
     * Stars
     * constructor

***********************************************************************/
ach::Stars::Stars() : ParticleSystem(2.0f)
{
	age  = 0.0f;
	freq = 0.05f;

	for (int i = 0; i < 70; i++)
		add(rand() % RENDER_LAYER_BG_X);
}



/***********************************************************************
     * Stars
     * destructor

***********************************************************************/
ach::Stars::~Stars()
{
}



/***********************************************************************
     * Stars
     * update

***********************************************************************/
bool ach::Stars::update()
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
     * Stars
     * check

***********************************************************************/
bool ach::Stars::check(ach::Particle *particle)
{
	return particle->pos.x >= 0.0f;
}



/***********************************************************************
     * Stars
     * add

***********************************************************************/
void ach::Stars::add(float x)
{
	unsigned char rnd = rand() % 7;
	unsigned char clr = 63 + rnd * 32;

	particles.push_back(new ach::Particle());

	particles.back()->pos = sf::Vector2f(x, rand() % RENDER_LAYER_BG_Y);
	particles.back()->vel = sf::Vector2f(-120.0f - rnd * 20.0f, 0.0f);
	particles.back()->acc = sf::Vector2f(0.0f, 0.0f);
	particles.back()->spr = spr;
	particles.back()->clr = sf::Color(clr, clr, clr);
}
