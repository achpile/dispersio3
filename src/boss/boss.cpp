#include "meta/headers.hpp"


/***********************************************************************
     * Boss
     * constructor

***********************************************************************/
ach::Boss::Boss(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
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

	if (rect.intersects(_rect))
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
	     if (!strcmp(json_object_get_string(obj, "name"), "Main")) return new ach::BossMain(_world, obj);
	else if (!strcmp(json_object_get_string(obj, "name"), "None")) return new ach::BossNone(_world, obj);

	return new ach::BossNone(_world, obj);
}
