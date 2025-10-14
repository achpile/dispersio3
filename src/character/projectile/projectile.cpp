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
	active  = false;
	bounces = base->bounces;
	model   = new ach::Model(base->sheet);
	tracer  = createTracer();

	phys.init(sf::Vector2f(base->radius * 2.0f, base->radius * 2.0f));
	delay.set(base->delay);

	world->map->gfx.push_back(tracer);

	model->setScale(base->scale);
	model->setColor(base->color);

	tracer->color = base->colorTracer;

	phys.acc.y = base->gravity;
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

	if (delay.update())
		return alive;
	else
		active = true;

	phys.update();
	model->update();

	line.b = phys.pos;
	line.calc();

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
	active = false;
	line.a = phys.pos;
	line.b = phys.pos;
	last   = phys.pos;

	tracer->init();
	delay.reset();
	phys.calc();
}



/***********************************************************************
     * Projectile
     * hit

***********************************************************************/
void ach::Projectile::hit(sf::Vector2f n)
{
	world->map->gfx.push_back(createImpact(n));
	sm->play(base->bump->snd);
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
	angle += phys.vel.x * 4.0f * tm->get();

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

	int   c = base->count * 4;
	float a = (MATH_PI * 2.0f) / c;

	for (int i = 0; i < c; i++)
	{
		ach::Projectile *proj = new ach::Projectile(world, base->explosion);

		proj->enemy    = enemy;
		proj->phys.vel = vector_set_len(vector_create(a * i), base->force);
		proj->phys.pos = phys.pos;
		proj->init();

		world->map->projectiles.push_back(proj);
	}
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
