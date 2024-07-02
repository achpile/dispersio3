#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::DataProjectile *_base, sf::Vector2f pos)
{
	base   = _base;
	alive  = true;
	model  = new ach::Model(base->sheet);
	tracer = ach::Tracer::create(base->tracer, &phys);

	phys.init(sf::Vector2f(0.0f, 0.0f));
	phys.pos = pos;

	model->setScale(base->scale);
	model->setColor(base->color);

	tracer->color = base->colorTracer;
	tracer->init();

	if (flag_get(base->flags, ach::ProjectileFlag::pfGravity))
		phys.acc.y = PHYS_GRAVITY / 4.0f;
}



/***********************************************************************
     * Projectile
     * destructor

***********************************************************************/
ach::Projectile::~Projectile()
{
	delete model;
	delete tracer;
}



/***********************************************************************
     * Projectile
     * update

***********************************************************************/
bool ach::Projectile::update()
{
	phys.update();
	model->update();
	tracer->update();

	return alive;
}



/***********************************************************************
     * Projectile
     * render

***********************************************************************/
void ach::Projectile::render()
{
	tracer->render();
	model->render(phys.pos);
}
