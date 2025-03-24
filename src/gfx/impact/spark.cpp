#include "meta/headers.hpp"


/***********************************************************************
     * ImpactSpark
     * constructor

***********************************************************************/
ach::ImpactSpark::ImpactSpark(sf::Vector2f _pos, sf::Vector2f _dir, sf::Color _color) : Impact(_pos, _dir, _color)
{
	particle = new ach::ParticleSystemSplash(PARTICLE_SPARK_SIZE);

	particle->layer    = ach::RenderLayer::rlGame;
	particle->realtime = false;

	particle->pos      = pos;
	particle->dir      = dir;
	particle->color    = color;
	particle->cone     = MATH_PI / 2.0f;
	particle->life     = 0.1f;
	particle->speed    = 100.0f;
	particle->gravity  = true;

	particle->init(4);
}



/***********************************************************************
     * ImpactSpark
     * destructor

***********************************************************************/
ach::ImpactSpark::~ImpactSpark()
{
	delete particle;
}



/***********************************************************************
     * ImpactSpark
     * update

***********************************************************************/
bool ach::ImpactSpark::update()
{
	return particle->update();
}



/***********************************************************************
     * ImpactSpark
     * render

***********************************************************************/
void ach::ImpactSpark::render()
{
	particle->render();
}
