#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base, sf::Vector2f pos)
{
	world   = _world;
	base    = _base;
	flip    = false;
	alive   = true;
	angle   = 0.0f;
	bounces = base->bounces;
	model   = new ach::Model(base->sheet);
	tracer  = createTracer();

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
	if (!alive)
		return false;

	line.a = phys.pos;

	phys.update();
	model->update();
	tracer->update();

	line.b = phys.pos;
	line.calc();

	range -= line.l;

	if (range <= 0.0f)
		destroy();

	rotation();
	direction();

	return alive;
}



/***********************************************************************
     * Projectile
     * render

***********************************************************************/
void ach::Projectile::render()
{
	if (!alive)
		return;

	tracer->render();
	model->render(phys.pos);
}



/***********************************************************************
     * Projectile
     * hit

***********************************************************************/
void ach::Projectile::hit(sf::Vector2f n)
{
	world->gfx.push_back(createImpact(n));
	sm->play(base->sfxBump);
	tracer->correct();

	if (bounces--)
		phys.vel = vector_mirror(phys.vel, n);
	else
		destroy();
}



/***********************************************************************
     * Projectile
     * destroy

***********************************************************************/
void ach::Projectile::destroy()
{
	explode();

	alive = false;
}



/***********************************************************************
     * Projectile
     * rotation

***********************************************************************/
void ach::Projectile::rotation()
{
	if (!flag_get(base->flags, ach::ProjectileFlag::pfRotation))
		return;

	angle += phys.vel.x * tm->frame * 4.0f;

	model->angle = angle;
}



/***********************************************************************
     * Projectile
     * direction

***********************************************************************/
void ach::Projectile::direction()
{
	if (!flag_get(base->flags, ach::ProjectileFlag::pfDirection))
		return;

	if (vector_len(phys.vel) == 0.0f)
		return;

	angle = MATH_DEG * vector_angle(phys.vel);

	if (flip)
	{
		model->scale.x = -1.0f;
		model->angle   = 180 - angle;
	}
	else
	{
		model->scale.x = 1.0f;
		model->angle   = angle;
	}
}



/***********************************************************************
     * Projectile
     * explode

***********************************************************************/
void ach::Projectile::explode()
{
	if (!flag_get(base->flags, ach::ProjectileFlag::pfExplosive))
		return;

	world->gfx.push_back(new ach::EffectExplosion(base->explosion, phys.pos, base->explosionR));
	sm->play(base->sfxExplosion);
}



/***********************************************************************
     * Projectile
     * createTracer

***********************************************************************/
ach::Tracer* ach::Projectile::createTracer()
{
	switch (base->tracer)
	{
		case ach::TracerType::ttNone : return new ach::Tracer     (&phys);
		case ach::TracerType::ttLine : return new ach::TracerLine (&phys);
		case ach::TracerType::ttSmoke: return new ach::TracerSmoke(&phys);

		default                      : return new ach::Tracer     (&phys);
	}
}



/***********************************************************************
     * Projectile
     * createImpact

***********************************************************************/
ach::Impact* ach::Projectile::createImpact(sf::Vector2f n)
{
	switch (base->impact)
	{
		case ach::ImpactType::itNone : return new ach::Impact     (phys.pos, n, base->colorImpact);
		case ach::ImpactType::itSpark: return new ach::ImpactSpark(phys.pos, n, base->colorImpact);

		default                      : return new ach::Impact     (phys.pos, n, base->colorImpact);
	}
}
