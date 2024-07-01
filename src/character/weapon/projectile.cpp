#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::DataProjectile *_base)
{
	base   = _base;
	alive  = true;
	model  = new ach::Model(base->sheet);
	tracer = new ach::Tracer(&phys);

	model->setScale(base->scale);
	model->setColor(base->color);

	phys.init(sf::Vector2f(0.0f, 0.0f));

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
