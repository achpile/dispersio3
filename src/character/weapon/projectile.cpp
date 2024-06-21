#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::DataProjectile *_base)
{
	base  = _base;
	alive = true;
	model = new ach::Model(base->sheet);

	model->setScale(base->scale);
	model->setColor(base->color);

	phys.init(sf::Vector2f(0.0f, 0.0f));
}



/***********************************************************************
     * Projectile
     * destructor

***********************************************************************/
ach::Projectile::~Projectile()
{
	delete model;
}



/***********************************************************************
     * Projectile
     * update

***********************************************************************/
bool ach::Projectile::update()
{
	phys.update();
	model->update();

	return alive;
}



/***********************************************************************
     * Projectile
     * render

***********************************************************************/
void ach::Projectile::render()
{
	model->render(phys.pos);
}
