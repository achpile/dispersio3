#include "meta/headers.hpp"


/***********************************************************************
     * EffectBreak
     * constructor

***********************************************************************/
ach::EffectBreak::EffectBreak(sf::Vector2f pos, sf::Sprite *spr)
{
	particle = new ach::ParticleSystemSplash(8.0f);

	particle->layer    = ach::RenderLayer::rlFront;
	particle->realtime = false;

	particle->pos      = pos;
	particle->dir      = sf::Vector2f(0.0f, -1.0f);
	particle->life     = 0.25f;
	particle->speed    = 100.0f;
	particle->gravity  = true;
	particle->rotate   = true;

	sf::IntRect r      = spr->getTextureRect();

	particle->spr->setTexture(spr->getTexture());
	particle->spr->setTextureRect(r);

	particle->add(-3.0f * MATH_PI / 4.0f);
	particle->add(      - MATH_PI / 4.0f);
	particle->add(        MATH_PI / 4.0f);
	particle->add( 3.0f * MATH_PI / 4.0f);

	particle->particles[0]->pos += sf::Vector2f(-4.0f, -4.0f);
	particle->particles[1]->pos += sf::Vector2f( 4.0f, -4.0f);
	particle->particles[2]->pos += sf::Vector2f( 4.0f,  4.0f);
	particle->particles[3]->pos += sf::Vector2f(-4.0f,  4.0f);

	particle->particles[0]->rect = sf::IntRect(r.left              , r.top               , r.width / 2, r.height / 2);
	particle->particles[1]->rect = sf::IntRect(r.left + r.width / 2, r.top               , r.width / 2, r.height / 2);
	particle->particles[2]->rect = sf::IntRect(r.left + r.width / 2, r.top + r.height / 2, r.width / 2, r.height / 2);
	particle->particles[3]->rect = sf::IntRect(r.left              , r.top + r.height / 2, r.width / 2, r.height / 2);
}



/***********************************************************************
     * EffectBreak
     * destructor

***********************************************************************/
ach::EffectBreak::~EffectBreak()
{
	delete particle;
}



/***********************************************************************
     * EffectBreak
     * update

***********************************************************************/
bool ach::EffectBreak::update()
{
	particle->scale = (particle->life - particle->age) / particle->life;

	return particle->update();
}



/***********************************************************************
     * EffectBreak
     * render

***********************************************************************/
void ach::EffectBreak::render()
{
	particle->render();
}
