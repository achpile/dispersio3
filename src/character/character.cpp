#include "meta/headers.hpp"


/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, json_t *obj)
{
	init(_world, db->getCharacter(json_object_get_string(obj, "name")), vector_json_center(obj), obj);
}



/***********************************************************************
     * Character
     * constructor

***********************************************************************/
ach::Character::Character(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f _spawn)
{
	init(_world, _base, _spawn, NULL);
}



/***********************************************************************
     * Character
     * destructor

***********************************************************************/
ach::Character::~Character()
{
	delete ai;
	delete body;
	delete weapon;
}



/***********************************************************************
     * Character
     * update

***********************************************************************/
bool ach::Character::update()
{
	if (!visible())
		return true;

	body->update();

	if (!alive)
	{
		if (spawner.update())
			return true;

		respawn();
	}


	weapon->aim(phys.pos + body->barrel, aim);
	weapon->update();

	if (phys.grounded && !landed)
		sm->play(base->sndLand->snd);

	landed = phys.grounded;

	return true;
}



/***********************************************************************
     * Character
     * render

***********************************************************************/
void ach::Character::render()
{
	if (!visible())
		return;

	body->render();
}



/***********************************************************************
     * Character
     * init

***********************************************************************/
void ach::Character::init(ach::ProcessWorld *_world, ach::DataCharacter *_base, sf::Vector2f _spawn, json_t *obj)
{
	world      = _world;
	base       = _base;
	spawn      = _spawn;
	ai         = ach::AI::create(this, base->ai, obj);
	body       = ach::Body::create(this, base->model);
	weapon     = new ach::Weapon(world, this, base->weapon);
	speed      = base->speed;
	jumping    = base->jumping;


	phys.init(base->hitbox);
	spawner.set(GAME_PLAYER_RESPAWN);

	body->setColor(base->color);
	weapon->barrel = base->barrel;

	respawn();
}



/***********************************************************************
     * Character
     * visible

***********************************************************************/
bool ach::Character::visible()
{
	return world->map->cam->check(phys.rect);
}



/***********************************************************************
     * Character
     * process

***********************************************************************/
void ach::Character::process()
{
	if (!alive)
		return;

	if (!visible())
		return;

	ai->update();
}



/***********************************************************************
     * Character
     * respawn

***********************************************************************/
void ach::Character::respawn()
{
	alive    = true;
	landed   = true;
	phys.pos = spawn;

	spawner.reset();
	body->spawn();
	reset();
}



/***********************************************************************
     * Character
     * reset

***********************************************************************/
void ach::Character::reset()
{
	aim = sf::Vector2f(1.0f, 0.0f);
	dir = sf::Vector2i(1, 0);

	phys.reset();

	body->reset();
	ai->reset();
}



/***********************************************************************
     * Character
     * gateway

***********************************************************************/
void ach::Character::gateway(sf::FloatRect dest)
{
	phys.pos      = vector_placement(dest, phys.rect);
	phys.vel      = sf::Vector2f(0.0f, 0.0f);
	phys.grounded = true;
	phys.moving   = false;

	phys.calc();
}



/***********************************************************************
     * Character
     * hit

***********************************************************************/
bool ach::Character::hit(ach::Projectile *projectile)
{
	if (enemy == projectile->enemy)
		return false;

	if (!alive)
		return false;

	if (!projectile->alive)
		return false;

	bool res;

	res = collision_box_vs_line(phys.rect, projectile->line, NULL, NULL);

	if (!res)
		res = collision_box_vs_box(phys.rect, projectile->phys.rect, NULL, NULL);


	if (res)
	{
		projectile->destroy();
		die();
	}

	return res;
}



/***********************************************************************
     * Character
     * die

***********************************************************************/
void ach::Character::die()
{
	alive = false;

	sm->play(base->sndDie->snd);
	world->map->gfx.push_back(new ach::EffectSplash(phys.pos, sf::Color::White, MATH_PI, 16));
}



/***********************************************************************
     * Character
     * move

***********************************************************************/
void ach::Character::move(int d)
{
	phys.moving = true;
	phys.vel.x  = speed * d;
}



/***********************************************************************
     * Character
     * jump

***********************************************************************/
void ach::Character::jump()
{
	if (!phys.grounded)
		return;

	if (phys.jumpdown)
		return;

	phys.vel.y = -jumping;

	sm->play(base->sndJump->snd);
}



/***********************************************************************
     * Character
     * use

***********************************************************************/
void ach::Character::use()
{
	if (!phys.grounded)
		return;

	world->map->use(this);
}
