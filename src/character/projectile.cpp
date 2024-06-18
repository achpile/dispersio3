#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::DataProjectile *_base)
{
	base  = _base;
	sheet = base->sheet->sheet;
	alive = true;
	scale = sf::Vector2f(base->scale, base->scale);

	phys.init(sf::Vector2f(0.0f, 0.0f));
	anim.init(sheet->spr.size());
}



/***********************************************************************
     * Projectile
     * destructor

***********************************************************************/
ach::Projectile::~Projectile()
{
}



/***********************************************************************
     * Projectile
     * update

***********************************************************************/
bool ach::Projectile::update()
{
	phys.update();

	return alive;
}



/***********************************************************************
     * Projectile
     * render

***********************************************************************/
void ach::Projectile::render()
{
	sf::Sprite *spr = sheet->spr[anim.frame];

	spr->setColor(base->color);
	spr->setScale(scale);
	spr->setPosition(phys.pos);

	rm->draw(spr, ach::RenderLayer::rlGame);
}
