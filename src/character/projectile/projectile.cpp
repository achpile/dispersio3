#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::ProcessWorld *_world, ach::DataProjectile *_base)
{
	world   = _world;
	base    = _base;
	flip    = false;
	alive   = true;
	angle   = 0.0f;
	bounces = base->bounces;
	model   = new ach::Model(base->sheet);
	tracer  = createTracer();

	phys.init(sf::Vector2f(base->radius * 2.0f, base->radius * 2.0f));

	world->map->gfx.push_back(tracer);

	model->setScale(base->scale);
	model->setColor(base->color);

	tracer->color = base->colorTracer;

	if (base->gravity)
		phys.acc.y = PHYS_GRAVITY / 2.0f;
}



/***********************************************************************
     * Projectile
     * destructor

***********************************************************************/
ach::Projectile::~Projectile()
{
	delete model;

	tracer->alive = false;
}



/***********************************************************************
     * Projectile
     * update

***********************************************************************/
bool ach::Projectile::update()
{
	if (!alive)
		return false;

	if (!visible())
		return false;

	line.a = last;
	last   = line.b;

	phys.update();
	model->update();

	line.b = phys.pos;
	line.calc();

	range -= line.l;

	if (range <= 0.0f)
		destroy();

	switch (base->orient)
	{
		case ach::OrientType::otDirection: direction(); break;
		case ach::OrientType::otRotation : rotation() ; break;
		case ach::OrientType::otNone     :              break;
	}

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

	model->render(phys.pos);
}



/***********************************************************************
     * Projectile
     * visible

***********************************************************************/
bool ach::Projectile::visible()
{
	return world->map->cam->check(phys.rect);
}



/***********************************************************************
     * Projectile
     * init

***********************************************************************/
void ach::Projectile::init()
{
	line.a = phys.pos;
	line.b = phys.pos;
	last   = phys.pos;

	tracer->init();
}



/***********************************************************************
     * Projectile
     * hit

***********************************************************************/
void ach::Projectile::hit(sf::Vector2f n)
{
	world->map->gfx.push_back(createImpact(n));
	sm->play(base->sfxBump->snd);
	tracer->correct();

	if (bounces--)
	{
		phys.vel = vector_mirror(phys.vel, n);

		if (base->gravity)
			phys.vel *= PHYS_PROJECTILE_SLOW;
	}
	else
	{
		destroy();
	}
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
	angle += phys.vel.x * 4.0f * tm->get(ach::TimeSource::tsFrame);

	model->angle = angle;
}



/***********************************************************************
     * Projectile
     * direction

***********************************************************************/
void ach::Projectile::direction()
{
	if (vector_len(phys.vel) == 0.0f)
		return;

	angle = MATH_DEG * vector_angle(phys.vel);

	if (flip)
	{
		model->scale.x = -1.0f;
		model->angle   = angle - 180;
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
	if (!base->explosive)
		return;

	world->map->gfx.push_back(new ach::EffectSheet(base->explosion, phys.pos, base->explosionR * 2.0f));
	world->map->collideExplosion(this);
	sm->play(base->sfxExplosion->snd);
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
	}

	return new ach::Tracer(&phys);
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
	}

	return new ach::Impact(phys.pos, n, base->colorImpact);
}
