#include "meta/headers.hpp"


/***********************************************************************
     * Boss
     * constructor

***********************************************************************/
ach::Boss::Boss(ach::ProcessWorld *_world, json_t *obj)
{
	world = _world;
	id    = json_object_get_integer(obj, "id");
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

	unpress();
	respawn();
}



/***********************************************************************
     * Boss
     * search

***********************************************************************/
void ach::Boss::search()
{
	ach::Character *candidate = NULL;
	float dist = 0.0f;

	target = NULL;

	list_foreach(world->map->characters)
	{
		candidate = world->map->characters[i];

		if (candidate->enemy)
			continue;

		if (!candidate->visible())
			continue;

		if (!target || vector_len(rect_center(rect) - candidate->phys.pos) < dist)
		{
			target = candidate;
			dist   = vector_len(rect_center(rect) - candidate->phys.pos);
		}
	}
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
		search();
		world->map->close();
	}
}



/***********************************************************************
     * Boss
     * unpress

***********************************************************************/
void ach::Boss::unpress()
{
	list_foreach(buttons)
		buttons[i]->reset();
}



/***********************************************************************
     * Boss
     * press

***********************************************************************/
void ach::Boss::press()
{
	list_foreach(buttons)
		if (!buttons[i]->pressed)
			return;

	damage();
}



/***********************************************************************
     * Boss
     * activate

***********************************************************************/
void ach::Boss::activate()
{
	list_foreach(buttons)
		buttons[i]->activate();
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
