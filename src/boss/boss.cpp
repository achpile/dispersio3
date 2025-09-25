#include "meta/headers.hpp"


/***********************************************************************
     * Boss
     * constructor

***********************************************************************/
ach::Boss::Boss(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
	base  = db->getBoss(json_object_get_string(obj, "name"));
	rect  = vector_json_rect(obj);

	reset();
}



/***********************************************************************
     * Boss
     * destructor

***********************************************************************/
ach::Boss::~Boss()
{
}



/***********************************************************************
     * Boss
     * update

***********************************************************************/
bool ach::Boss::update()
{
	if (defeated)
		world->goal();

	return true;
}



/***********************************************************************
     * Boss
     * process

***********************************************************************/
void ach::Boss::process()
{
	if (active)
		handle();
}



/***********************************************************************
     * Boss
     * reset

***********************************************************************/
void ach::Boss::reset()
{
	active   = false;
	defeated = false;

	respawn();
}



/***********************************************************************
     * Boss
     * check

***********************************************************************/
void ach::Boss::check(sf::FloatRect _rect)
{
	if (active)
		return;

	sf::FloatRect intersection;

	if (rect.intersects(_rect, intersection) && intersection == _rect)
	{
		active = true;

		init();
		world->map->close();
	}
}



/***********************************************************************
     * Boss
     * create

***********************************************************************/
ach::Boss* ach::Boss::create(ach::ProcessWorld *_world, json_t *obj)
{
	ach::DataBoss *base = db->getBoss(json_object_get_string(obj, "name"));

	switch (base->type)
	{
		case ach::BossType::btNone: return new ach::BossNone(_world, obj);
		case ach::BossType::btMain: return new ach::BossMain(_world, obj);
	}

	return new ach::BossNone(_world, obj);
}
