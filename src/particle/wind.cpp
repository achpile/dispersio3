#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystemWind
     * constructor

***********************************************************************/
ach::ParticleSystemWind::ParticleSystemWind(sf::FloatRect _rect, ach::Direction _dir, float speed) : ParticleSystem(1.0f)
{
	age    = 0.0f;
	dir    = _dir;
	rect   = _rect;
	vel    = dir_vector_f(dir) * speed * 4.0f;
	layer  = ach::RenderLayer::rlGame;

	start  = rect_value(rect, !dir);
	side   = orient_rect_size(!dir_orient(dir), rect);
	offset = orient_rect_min (!dir_orient(dir), rect);

	freq   = side * 0.0005f;

	//   TODO:
	// freq depends on side AND speed
	// start count depends on side AND speed

	for (int i = 0; i < 10; i++)
		add(random_float(orient_rect_min(dir_orient(dir), rect), orient_rect_max(dir_orient(dir), rect)));
}



/***********************************************************************
     * ParticleSystemWind
     * destructor

***********************************************************************/
ach::ParticleSystemWind::~ParticleSystemWind()
{
}



/***********************************************************************
     * ParticleSystemWind
     * update

***********************************************************************/
bool ach::ParticleSystemWind::update()
{
	age += tm->get();

	while (age > freq)
	{
		age -= freq;
		add(start);
	}

	return true;
}



/***********************************************************************
     * ParticleSystemWind
     * process

***********************************************************************/
bool ach::ParticleSystemWind::process(ach::Particle *particle)
{
	return rect.contains(particle->pos);
}



/***********************************************************************
     * ParticleSystemWind
     * add

***********************************************************************/
void ach::ParticleSystemWind::add(float x)
{
	particles.push_back(new ach::Particle());

	orient_v_set( dir_orient(dir), &particles.back()->pos, x);
	orient_v_set(!dir_orient(dir), &particles.back()->pos, random_float(0.0f, side) + offset);

	particles.back()->vel   = vel * random_float(0.75f, 1.25f);
	particles.back()->spr   = spr;
	particles.back()->color = sf::Color(255, 255, 255, 150);

	particles.back()->calc();
}
